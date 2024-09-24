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
#include <dds/core/QosProvider.hpp>
#include <dds/core/cond/WaitSet.hpp>
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include <dds/domain/ddsdomain.hpp> //for ignore (i.e. echo off)
//#include "TaskController_dp.hpp"
#include "../app_utils.hpp"
#include "TC_logic.hpp"
using namespace std::chrono_literals;
#include <thread>     //for using the function sleep
#include <cstring>
rti::core::QosProviderParams provider_params;
dds::domain::DomainParticipant tc_dp = dds::core::null;
dds::sub::DataReader<DeviceInformation::Device_t> r_device = dds::core::null;
dds::sub::DataReader<DeviceInformation::DeviceElement_t> r_ddop_hierarchy = dds::core::null;
dds::sub::DataReader<Actuation::ControlHandlingCapabilities_t> r_ctrl_capables = dds::core::null;
dds::sub::DataReader<Actuation::ControlHandlingValues_t> r_ctrl_values = dds::core::null;
dds::pub::DataWriter<Actuation::ControlHandlingValues_t> w_ctrl_values = dds::core::null;
dds::sub::DataReader<GNSS::PositionData_t> r_gnss_position = dds::core::null;
static int TC_init(bool isCalledFromGuiNotCmd)
{
    // Catch ctr+c to allow for graceful program termination
    application::setup_signal_handlers();
    // is this line not required? What happens to the c#?
        // if (isCalledFromGuiNotCmd)
            // provider_params.url_profile({ "InformationModel/HSI_Standard_topics.xml"
            // , "InformationModel/HSI_generic_TcServer.xml" });
        // else
    provider_params.url_profile({ std::string(PATH_INFORMATION_MODEL) + "/HSI_Standard_topics.xml"
    , std::string(PATH_INFORMATION_MODEL) + "/HSI_generic_TcServer.xml" });
    rti::core::default_qos_provider_params(provider_params);
    rti::domain::register_type<DeviceInformation::Device_t>("Device_t");
    rti::domain::register_type<DeviceInformation::DeviceElement_t>("DeviceElement_t");
    rti::domain::register_type<Actuation::ControlHandlingCapabilities_t>("ControlHandlingCapabilities_t");
    rti::domain::register_type<Actuation::ControlHandlingValues_t>("ControlHandlingValues_t");
    rti::domain::register_type<GNSS::PositionData_t>("PositionData_t"); //TODO: consider renaming this topic and/or data type
    if (!isCalledFromGuiNotCmd)
        std::cout << "Starting TC" << std::endl;
    auto default_provider = dds::core::QosProvider::Default();
    tc_dp = default_provider.extensions().create_participant_from_config("Generic_TcServer::Generic_TcServer_dp");
    // Ignore messages from ourselves on all topics
    dds::domain::ignore(tc_dp, tc_dp.instance_handle());
    r_device = rti::sub::find_datareader_by_name<dds::sub::DataReader<DeviceInformation::Device_t>>(
        tc_dp, "s_device_::r_device");
    r_ddop_hierarchy = rti::sub::find_datareader_by_name<dds::sub::DataReader<DeviceInformation::DeviceElement_t>>(
        tc_dp, "s_ddop_hierarchy::r_ddop_hierarchy");
    r_ctrl_capables = rti::sub::find_datareader_by_name<dds::sub::DataReader<Actuation::ControlHandlingCapabilities_t>>(
        tc_dp, "s_ddi_linking::r_ddi_linking");
    r_ctrl_values = rti::sub::find_datareader_by_name<dds::sub::DataReader<Actuation::ControlHandlingValues_t>>(
        tc_dp, "s_pd_values_best_effort::r_pd_values_best_effort");
    w_ctrl_values = rti::pub::find_datawriter_by_name<dds::pub::DataWriter<Actuation::ControlHandlingValues_t>>(
        tc_dp, "p_pd_values_best_effort::w_pd_values_best_effort");
    r_gnss_position = rti::sub::find_datareader_by_name<dds::sub::DataReader<GNSS::PositionData_t>>(
        tc_dp, "s_gnss::r_gnss");    
    return 1;
}
static const char* HandlingGroup_e_2_cstring(const Actuation::HandlingGroup_e sample)
{
    char* HandlingGroup_e_text = "";
    switch (sample)
    {
    case Actuation::HandlingGroup_e::application_rate:
        HandlingGroup_e_text = "application_rate";
        break;
    case Actuation::HandlingGroup_e::fill_level:
        HandlingGroup_e_text = "fill_level";
        break;
    case Actuation::HandlingGroup_e::flow_rate:
        HandlingGroup_e_text = "flow_rate";
        break;
    case Actuation::HandlingGroup_e::seeding_depth:
        HandlingGroup_e_text = "seeding_depth";
        break;
    case Actuation::HandlingGroup_e::tillage_depth:
        HandlingGroup_e_text = "tillage_depth";
        break;
    case Actuation::HandlingGroup_e::working_height:
        HandlingGroup_e_text = "working_height";
        break;
    default:
        HandlingGroup_e_text = "other";
    }
    return HandlingGroup_e_text;
}
static const char* HandlingFeature_e_2_cstring(const Actuation::HandlingFeature_e sample)
{
    char* HandlingFeature_e_text = "";
    //TODO: move this to function and complete it
    switch (sample)
    {
    case Actuation::HandlingFeature_e::minimum:
        HandlingFeature_e_text = "minimum";
        break;
    case Actuation::HandlingFeature_e::maximum:
        HandlingFeature_e_text = "maximum";
        break;
    case Actuation::HandlingFeature_e::actual:
        HandlingFeature_e_text = "actual";
        break;
    case Actuation::HandlingFeature_e::setpoint:
        HandlingFeature_e_text = "setpoint";
        break;
    default:
        HandlingFeature_e_text = "other";
    }
    return HandlingFeature_e_text;
}
static const char* Unit_t_2_cstring(const Common::Unit_e sample)
{
    char* unit_text = "";
    //TODO: move this to function and complete it
    switch (sample)
    {
    case Common::Unit_e::kg:
        unit_text = "kg";
        break;
    case Common::Unit_e::count:
        unit_text = "";
        break;
    case Common::Unit_e::none:
        unit_text = "";
        break;
    case Common::Unit_e::m:
        unit_text = "m";
        break;
    case Common::Unit_e::m_2:
        unit_text = "m2";
        break;
    case Common::Unit_e::m_3:
        unit_text = "m3";
        break;
    case Common::Unit_e::s:
        unit_text = "s";
        break;
    default:
        unit_text = "other";
    }
    return unit_text;
}
// Concatenates two unit strings together, with an optional "/" separator if the bottom unit is empty
static char* concatenate_units(const char* unit_top, const char* unit_btm)
{
    size_t total_len = strlen(unit_top) + strlen(unit_btm) + 1;
    if (unit_btm[0] != '\0') {
        total_len++;
    }
    char* result = new char[total_len];
    strcpy_s(result, total_len, unit_top);
    if (unit_btm[0] != '\0') {
        strcat_s(result, total_len, "/");
    }
    strcat_s(result, total_len, unit_btm);
    return result;
}
// converts unit_t to a c string
static const char* Unit_t_2_cstring(const Common::Unit_t full_units_top_and_bottom)
{
    //Actuation::HandlingGroup_e handling_group = sample.data().handling_group();
    const char* unit_top = Unit_t_2_cstring(full_units_top_and_bottom.nominator());
    const char* unit_btm = Unit_t_2_cstring(full_units_top_and_bottom.denominator());
    return concatenate_units(unit_top, unit_btm);
}
void TC_logic_run(
    bool isCalledFromGuiNotCmd,
    void (*update_tank_cb)(float min_fill, float curr_fill, float max_fill),
    void (*update_Device_t_cb)(const char* id, const char* designator, const char* softwareversion,
        const char* friendly_name, const char* serialnumber, const char* structurelabel,
        const char* localizationlabel),
    void (*update_DeviceElement_t_cb)(const char* name, uint64_t element_ref_name, uint64_t element_ref_element_num,
        uint64_t parent_ref_name, uint64_t parent_ref__element_num),
    void (*update_ControlHandlingCapabilities_t_cb)(uint64_t element_ref_name, uint64_t element_ref_element_num,
        const char* handling_group, uint8_t option_nr, const char* unit),
    void (*update_ControlHandlingValues_t_cb)(uint64_t element_ref_name, uint64_t element_ref_element_num,
        const char* handling_feature, const char* handling_group, double value, const char* unit),
    double (*get_setpoint)(),
    void (*read_lat_lon_cb)(uint64_t name, double lat, double lon),
    void (*name_disconnect)(uint64_t name)
)
{
    //update_ControlHandlingValues_t_cb(0x123, 123, "dummy_handling_feature", "dummy_handling_group", 0.0, "dummy_unit");
    update_tank_cb(0, 0, 100);
    TC_init(isCalledFromGuiNotCmd);
    // LoanedSamples<Foo> is a container of LoanedSample<Foo> elements, which
    // contain the actual data (Foo) and the SampleInfo
    dds::sub::LoanedSamples<DeviceInformation::Device_t> Device_t_samples; // read is like preview and take is like read+remove
    dds::sub::LoanedSamples<DeviceInformation::DeviceElement_t> DeviceElement_t_samples;
    dds::sub::LoanedSamples<Actuation::ControlHandlingCapabilities_t> ControlHandlingCapabilities_t_samples;
    dds::sub::LoanedSamples<Actuation::ControlHandlingValues_t> ControlHandlingValues_t_samples;
    dds::sub::LoanedSamples<GNSS::PositionData_t> PositionData_t_samples;
    const uint64_t sprayer_NAME = 0xABCDEF01;
    const uint64_t sprayer_element_num_root = 10;
    double initial_rate = 1.23;
    Common::Unit_t unit_mass_per_area(Common::Unit_t(Common::Unit_e::kg, Common::Unit_e::m_3));
    Actuation::ControlHandlingValues_t pd_values_setpoint = Actuation::ControlHandlingValues_t(DeviceInformation::ElementReference_t(sprayer_NAME, sprayer_element_num_root),
        Actuation::HandlingFeature_e::setpoint, Actuation::HandlingGroup_e::application_rate, initial_rate, unit_mass_per_area);
    uint64_t name_to_remove = 0;
    int32_t generation_removed_prev = 0;
    int32_t generation_removed_next = 0;
    std::vector<dds::core::InstanceHandle> dead_instance_handles;
    while (application::run_application)
    {
        // read the setpoint from the user and write it
        pd_values_setpoint.value() = get_setpoint();
        w_ctrl_values.write(pd_values_setpoint);
        update_ControlHandlingValues_t_cb(pd_values_setpoint.element_ref().name(), pd_values_setpoint.element_ref().element_id(),
            HandlingFeature_e_2_cstring(pd_values_setpoint.handling_feature()),
            HandlingGroup_e_2_cstring(pd_values_setpoint.handling_group()),
            pd_values_setpoint.value(),
            Unit_t_2_cstring(pd_values_setpoint.unit()));
        /// Device_t_samples
        Device_t_samples = r_device.read();
        DeviceElement_t_samples = r_ddop_hierarchy.read();
        ControlHandlingCapabilities_t_samples = r_ctrl_capables.read();
        ControlHandlingValues_t_samples = r_ctrl_values.read();
        /// DeviceElement_t
        if (DeviceElement_t_samples.length() > 0)
        {
            for (unsigned int pos = 0; pos < DeviceElement_t_samples.length(); pos++) {
                auto sample_it = DeviceElement_t_samples[pos];
                if (!sample_it->info().valid()) {
                    continue;
                }
                // remove the device from the gui if it is not alive on he topic
                // TODO: this would be better in the service discovery topic when it is made
                dds::sub::status::InstanceState device_alive_state = sample_it->info().state().instance_state();
                if (device_alive_state != dds::sub::status::InstanceState::alive())
                {
                    //sample_it->info().state().view_state(dds::sub::status::ViewState::new_view());
                    //sample_it->info().state().sample_state(dds::sub::status::SampleState::not_read());
                    generation_removed_next++;
                    name_to_remove = sample_it.data().element_ref().name();
                    continue;
                }
                if (sample_it->info().rank().sample() != 0)
                    continue; //only want latest data
                name_to_remove = 0;
                generation_removed_next = generation_removed_prev;
                dds::sub::status::ViewState has_sample_already_been_read = sample_it->info().state().view_state();
                // only write to the GUI if the view state is new
                if (has_sample_already_been_read == dds::sub::status::ViewState::new_view())
                    update_DeviceElement_t_cb(sample_it.data().name().c_str(), sample_it.data().element_ref().name(),
                        sample_it.data().element_ref().element_id(), sample_it.data().parent_ref().name(),
                        sample_it.data().parent_ref().element_id());
            }
            //DeviceElement_t_samples.return_loan();
            if (name_to_remove != 0 && generation_removed_next != generation_removed_prev) {
                //if (name_to_remove != 0 ) {
                generation_removed_prev = generation_removed_next;
                name_disconnect(name_to_remove);
            }
        }
        if (Device_t_samples.length() > 0)
        {
            for (unsigned int pos = 0; pos < Device_t_samples.length(); pos++)
            {
                auto sample_it = Device_t_samples[pos];
                if (!sample_it->info().valid()) {
                    continue;
                }
                if (sample_it->info().rank().sample() != 0)
                    continue; //only want latest data
                
                dds::sub::status::ViewState has_sample_already_been_read = sample_it->info().state().view_state();
                // only write to the GUI if the view state is new
                if (has_sample_already_been_read == dds::sub::status::ViewState::new_view())
                    update_Device_t_cb(sample_it.data().id().c_str(), sample_it.data().designator().c_str(),
                        sample_it.data().software_version().c_str(), sample_it.data().name().c_str(),
                        sample_it.data().serial_number().c_str(), sample_it.data().structure_label().c_str(),
                        sample_it.data().localization_label().c_str());
            }
            //Device_t_samples.return_loan();
        }
        /// ControlHandlingCapabilities_t
        if (ControlHandlingCapabilities_t_samples.length() > 0)
        {
            for (unsigned int pos = 0; pos < ControlHandlingCapabilities_t_samples.length(); pos++) {
                auto sample_it = ControlHandlingCapabilities_t_samples[pos];
                if (!sample_it->info().valid()) {
                    continue;
                }
                if (sample_it->info().rank().sample() != 0)
                    continue; //only want latest data
                dds::sub::status::ViewState has_sample_already_been_read = sample_it->info().state().view_state();
                // only write to the GUI if the view state is new
                if (has_sample_already_been_read == dds::sub::status::ViewState::new_view())
                    update_ControlHandlingCapabilities_t_cb(sample_it.data().element_ref().name(), sample_it.data().element_ref().element_id(),
                        HandlingGroup_e_2_cstring(sample_it.data().handling_group()),
                        sample_it.data().option_nr(),
                        Unit_t_2_cstring(sample_it.data().unit()));
            }
        }
        /// ControlHandlingValues_t
        if (ControlHandlingValues_t_samples.length() > 0)
        {
            for (unsigned int pos = 0; pos < ControlHandlingValues_t_samples.length(); pos++) {
                auto sample_it = ControlHandlingValues_t_samples[pos];
                if (!sample_it->info().valid()) {
                    continue;
                }
                dds::sub::status::ViewState has_sample_already_been_read = sample_it->info().state().view_state();
                //dds::sub::status::SampleState has_sample_already_been_read = sample_it->info().state().sample_state();
                // only write to the GUI if the view state is new
                if (has_sample_already_been_read == dds::sub::status::ViewState::new_view())
                //if (has_sample_already_been_read == dds::sub::status::SampleState::not_read())
                    update_ControlHandlingValues_t_cb(sample_it.data().element_ref().name(), sample_it.data().element_ref().element_id(),
                        HandlingFeature_e_2_cstring(sample_it.data().handling_feature()),
                        HandlingGroup_e_2_cstring(sample_it.data().handling_group()),
                        sample_it.data().value(),
                        Unit_t_2_cstring(sample_it.data().unit()));
            }
        }
        PositionData_t_samples = r_gnss_position.read();
        if (PositionData_t_samples.length() > 0)
        {
            for (unsigned int pos = 0; pos < PositionData_t_samples.length(); pos++) {
                auto sample_it = PositionData_t_samples[pos];
                if (!sample_it->info().valid()) {
                    continue;
                }
                // check if the lat and lon are valid because they are optional in the struct so could be null
                if (sample_it.data().Lat().has_value() && sample_it.data().Lon().has_value()) {
                    read_lat_lon_cb(sample_it.data().NAME(), sample_it.data().Lat().value(), sample_it.data().Lon().value());
                }
            }
        }
        // Do things, at least put thread to sleep
        std::this_thread::sleep_for(0.1s);
        continue;
    }
}
void TC_logic_stop()
{
    application::run_application = false;
}
