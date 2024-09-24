// MIT License
// 
// Copyright (c) 2024 Samuel Brodie, Timo Oksanen, Henri Hornburg, Daniel Ostermeier, Maksim Pavlov Technical University of Munich
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#include <thread>
#include <random>
#include <dds/core/QosProvider.hpp>
#include "../app_utils.hpp"
#include <dds/core/cond/WaitSet.hpp>
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include <dds/domain/ddsdomain.hpp> //for ignore (i.e. echo off)

using namespace std::chrono_literals;


// Example specifications of our sprayer
namespace {
    constexpr unsigned NUMBER_SPRAYER_SECTIONS{ 500 };
    constexpr auto LOOP_REFRESH_TIME = 10ms; // Refresh time of the sprayer - one update to the topic roughly every 10ms

    ////////////////
    /// setup isobus values element numbers, NAME etc ///
    ////////////////
    const uint64_t sprayer_NAME = 0xABCDEF01;
    const uint64_t sprayer_element_ref_root = 10;
    const uint64_t sprayer_element_ref_tank = 20;
    const uint64_t sprayer_element_ref_boom = 30;
    const uint64_t sprayer_element_ref_sections_start = 40; // Reference of first section - reference of last section is sprayer_element_ref_sections_start+NUMBER_SPRAYER_SECTIONS - 1 
    const Common::Unit_t unit_mass_per_area(Common::Unit_t(Common::Unit_e::kg, Common::Unit_e::m_3));
}

// Some utility methods used for this showcase
static void cout_Device_t_data(DeviceInformation::Device_t Device_t_info);
static void cout_DeviceElement_t_data(DeviceInformation::DeviceElement_t DeviceElement_t_info);
static Actuation::ControlHandlingValues_t simulate_section(const DeviceInformation::ElementReference_t& section_reference, const double setpoint);

int main()
{
    ////////////////
    /// README ///
    ////////////////
    // 
    // 
    // This program's sole purpose is to showcase the overall potential of using Ethernet based communication with a DDS based middleware. 
    // It shall specifically highight the bandwith advantages over a CAN-based communication as with the current ISOBUS implementation.
    // 
    // This program should NOT be referred to as an example for good programming practices regarding the RTI Connext API, 
    // or even as a desirable implementation structur for an actual distributed system.
    // 
    // For a more thorough suggestion on how a real-world - scalable - implementation can look like, 
    // please refer to the proof of concept delivered in the "Sprayer_dp" folder.
    // 
    // 
    ////////////////
    /// README ///
    ////////////////




    ////////////////
    /// Preamble ///
    ////////////////
    // Catch ctr+c to allow for graceful program termination
    application::setup_signal_handlers();

    // Setup and register types from XML files
    rti::core::QosProviderParams provider_params;
    provider_params.url_profile({ std::string(PATH_INFORMATION_MODEL) + "/HSI_Standard_topics.xml"
        , std::string(PATH_INFORMATION_MODEL)+"/TUM_simple_sprayer.xml" });
    rti::core::default_qos_provider_params(provider_params);
    rti::domain::register_type<DeviceInformation::Device_t>("Device_t");
    rti::domain::register_type<DeviceInformation::DeviceElement_t>("DeviceElement_t");
    rti::domain::register_type<Actuation::ControlHandlingCapabilities_t>("ControlHandlingCapabilities_t");
    rti::domain::register_type<Actuation::ControlHandlingValues_t>("ControlHandlingValues_t");

    std::cout << "Starting" << std::endl;


    ////////////////
    /// setup DDS participants, readers/writers etc ///
    ////////////////
    auto default_provider = dds::core::QosProvider::Default();
    dds::domain::DomainParticipant sprayer_root_dp =
        default_provider.extensions().create_participant_from_config("Simple_sprayer_lib::Simple_sprayer_dp");

    // Ignore messages from ourselves on all topics
    // https://community.rti.com/kb/how-do-i-get-datareader-ignore-datawriter-belongs-same-domainparticipant
    dds::domain::ignore(sprayer_root_dp, sprayer_root_dp.instance_handle());

    dds::pub::DataWriter<DeviceInformation::Device_t> w_sprayer_dvc =
        rti::pub::find_datawriter_by_name<dds::pub::DataWriter<DeviceInformation::Device_t>>(sprayer_root_dp,
            "p_device_::w_device");
    dds::pub::DataWriter<DeviceInformation::DeviceElement_t> w_spray_dets =
        rti::pub::find_datawriter_by_name<dds::pub::DataWriter<DeviceInformation::DeviceElement_t>>(sprayer_root_dp,
            "p_ddop_hierarchy::w_ddop_hierarchy");
    dds::pub::DataWriter<Actuation::ControlHandlingCapabilities_t> w_spray_capabilites =
        rti::pub::find_datawriter_by_name<dds::pub::DataWriter<Actuation::ControlHandlingCapabilities_t>>(sprayer_root_dp,
            "p_ddi_linking::w_ddi_linking");
    dds::pub::DataWriter<Actuation::ControlHandlingValues_t> w_spray_values =
        rti::pub::find_datawriter_by_name<dds::pub::DataWriter<Actuation::ControlHandlingValues_t>>(sprayer_root_dp,
            "p_pd_values_best_effort::w_pd_values_best_effort");
    dds::sub::DataReader<Actuation::ControlHandlingValues_t> r_spray_values =
        rti::sub::find_datareader_by_name<dds::sub::DataReader<Actuation::ControlHandlingValues_t>>(sprayer_root_dp,
            "s_pd_values_best_effort::r_pd_values_best_effort");


    ////////////////
    /// put isobus data in the DDS types
    /// (types are generated from rti codegen) ///
    ////////////////

    /// DDOP hierarchy (Device_t and DeviceElement_t types) ///

    //// root
    DeviceInformation::Device_t sprayer_dvc_info("DVC-1", "Sprayer", "1.0", "0xABCDEF01", "20050127", "53707261796572", "FF000000006E65");

    //// Sprayer
    DeviceInformation::DeviceElement_t sprayer_det_info("Sprayer",
        DeviceInformation::ElementReference_t(sprayer_NAME, sprayer_element_ref_root),
        DeviceInformation::ElementReference_t(0, 0));

    //// Tank
    DeviceInformation::DeviceElement_t tank_det_info("Tank",
        DeviceInformation::ElementReference_t(sprayer_NAME, sprayer_element_ref_tank),
        DeviceInformation::ElementReference_t(sprayer_NAME, sprayer_element_ref_root));

    //// Boom
    DeviceInformation::DeviceElement_t boom_det_info("Boom",
        DeviceInformation::ElementReference_t(sprayer_NAME, sprayer_element_ref_boom),
        DeviceInformation::ElementReference_t(sprayer_NAME, sprayer_element_ref_root));

    //// sections
    const std::string section_des{ "Section " };
    const unsigned sections_reference_offset = 3; // Element references before the sections
    DeviceInformation::DeviceElement_t section_det_infos[NUMBER_SPRAYER_SECTIONS];

    // Arbitrary number of subdivisions in sections
    for (unsigned i = 0; i < NUMBER_SPRAYER_SECTIONS; i++) {
        section_det_infos[i] = DeviceInformation::DeviceElement_t(section_des + std::to_string(i + 1),
            DeviceInformation::ElementReference_t(sprayer_NAME, sprayer_element_ref_sections_start + i),
            DeviceInformation::ElementReference_t(sprayer_NAME, sprayer_element_ref_boom));
    }


    ////////////////
    /// ControlHandlingCapabilities_t are like DDIs, and they are each assigned to an element (like ISOBUS DDIs)
    /// the difference is that instead of a number they are built from a handling group (e.g app rate) and a list of possible units
    /// e.g. if an implement 
    /// (types are generated from rti codegen) ///
    ////////////////
    /// DDOP control handling (i.e. assign DDIs to device elements (ControlHandlingCapabilities_t type) ///
    
    const int option_number = 2;
    Actuation::ControlHandlingCapabilities_t sprayer_det_capabls(sprayer_det_info.element_ref(),
        Actuation::HandlingGroup_e::application_rate,
        option_number, unit_mass_per_area);


    ////////////////
    /// write to DDS topics ///
    ////////////////
    w_sprayer_dvc.write(sprayer_dvc_info);
    cout_Device_t_data(sprayer_dvc_info);
    w_spray_dets.write(sprayer_det_info);
    cout_DeviceElement_t_data(sprayer_det_info);
    w_spray_dets.write(tank_det_info);
    cout_DeviceElement_t_data(tank_det_info);
    w_spray_dets.write(boom_det_info);
    cout_DeviceElement_t_data(boom_det_info);

    // Arbitrary number of subdivisions in sections
    for (unsigned i = 0; i < NUMBER_SPRAYER_SECTIONS; i++)
    {
        w_spray_dets.write(section_det_infos[i]);
        cout_DeviceElement_t_data(section_det_infos[i]);
    }

    // Announce own control-handling capabilities
    w_spray_capabilites.write(sprayer_det_capabls);

    // This vector contains the setpoints of all sections (zero-initialized)
    double setpoints_sections[NUMBER_SPRAYER_SECTIONS]={};

    dds::sub::LoanedSamples<Actuation::ControlHandlingValues_t>  ControlHandlingValues_t_samples;
    while (application::run_application)
    {
        // Write sprayer device information
        w_sprayer_dvc.write(sprayer_dvc_info);

        // Write all actual values of the sections to the topics
        for (unsigned i = 0; i < NUMBER_SPRAYER_SECTIONS; i++)
        {
            w_spray_values.write(simulate_section(section_det_infos[i].element_ref(), setpoints_sections[i]));
        }


        // Receive new setpoints, e.g., from the taskcontroller 
        ControlHandlingValues_t_samples = r_spray_values.take();
        //std::cout << ControlHandlingValues_t_samples.length() << std::endl;
        for (unsigned pos = 0; pos < ControlHandlingValues_t_samples.length(); pos++) 
        {
            auto sample_it = ControlHandlingValues_t_samples[pos];
            std::cout << "Received_message" << std::endl;
            // Check if message contains valid data and refers to the setpoint of the section
            if (sample_it->info().valid() && sample_it.data().handling_feature() == Actuation::HandlingFeature_e::setpoint)
            {
                // Section index in array
                int section_index = sample_it.data().element_ref().element_id() - sprayer_element_ref_sections_start;
                
                if (section_index >= 0 && section_index < NUMBER_SPRAYER_SECTIONS)
                {
                    // Update newly received section setpoint
                    setpoints_sections[section_index] = sample_it->data().value();
                }
            }
        }

        // Return "loaned memory" to middleware - we must not hold any pointers to that memory after this operation!
        ControlHandlingValues_t_samples.return_loan();


        std::this_thread::sleep_for(LOOP_REFRESH_TIME);
    }
}


/// <summary>
/// print values to the terminal
/// </summary>
/// <param name="Device_t_info"></param>
static void cout_Device_t_data(DeviceInformation::Device_t Device_t_info)
{
    std::cout << "Device: " << Device_t_info.id()
        << "\twith designator " << Device_t_info.designator()
        << "\tsoftware version " << Device_t_info.software_version() << std::endl
        << "\tclient name " << Device_t_info.name()
        << "\tserial number " << Device_t_info.serial_number() << std::endl
        << "\tstructure label " << Device_t_info.structure_label()
        << "\tlocalization label " << Device_t_info.localization_label() << std::endl;
}

static void cout_DeviceElement_t_data(DeviceInformation::DeviceElement_t DeviceElement_t_info)
{
    std::cout << "DeviceElement: "
        << "\tname: " << DeviceElement_t_info.name()
        << "\telement_ref: " << DeviceElement_t_info.element_ref() << std::endl
        << "\tparent_ref: " << DeviceElement_t_info.parent_ref() << std::endl;
}

// Simulate some simple section behavior: Randomized noise
static Actuation::ControlHandlingValues_t simulate_section(const DeviceInformation::ElementReference_t& section_reference, const double setpoint)
{
    // Just add some random noise to the setpoint value and return it as actual
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(-(setpoint / 10 + 1), setpoint / 10 + 1); // range [-setpoint / 10 + 1, setpoint / 10 + 1)

    const double computed_actual = setpoint == 0 ? 0 : setpoint + dis(e);
    
    return Actuation::ControlHandlingValues_t(section_reference,
        Actuation::HandlingFeature_e::actual, Actuation::HandlingGroup_e::application_rate, computed_actual, unit_mass_per_area);
}