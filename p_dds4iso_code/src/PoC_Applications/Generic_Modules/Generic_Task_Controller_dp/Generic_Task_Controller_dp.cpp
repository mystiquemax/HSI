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
#include <dds/domain/ddsdomain.hpp>
#include "Task_Controller_dp.hpp"

namespace Tractor
{
    Task_Controller_dp::Task_Controller_dp(const std::string& domain_participant_name)
    {
        auto default_provider = dds::core::QosProvider::Default();
        dp = default_provider.extensions().create_participant_from_config(domain_participant_name);

        // Ignore messages from ourselves on all topics
        dds::domain::ignore(dp, dp.instance_handle());

        r_diagnostics = rti::sub::find_datareader_by_name<dds::sub::DataReader<Diagnostics::Diagnostic_t>>(dp, "s_diagnostics::r_diagnostics");
        waitset.attach_condition(dds::sub::cond::ReadCondition(
            r_diagnostics,
            dds::sub::status::DataState::any(),
            std::bind(&Task_Controller_dp::r_diagnostics_read_callback, this)));
        if (r_diagnostics == dds::core::null)
        {
            throw std::runtime_error("Looking up r_diagnostics failed. Are all necessary DDS-XML files loaded?");
        }
        r_device_element = rti::sub::find_datareader_by_name<dds::sub::DataReader<DeviceInformation::DeviceElement_t>>(dp, "s_device_element::r_device_element");
        waitset.attach_condition(dds::sub::cond::ReadCondition(
            r_device_element,
            dds::sub::status::DataState::any(),
            std::bind(&Task_Controller_dp::r_device_element_read_callback, this)));
        if (r_device_element == dds::core::null)
        {
            throw std::runtime_error("Looking up r_device_element failed. Are all necessary DDS-XML files loaded?");
        }
        r_device_element_connectors = rti::sub::find_datareader_by_name<dds::sub::DataReader<DeviceInformation::ConnectorList_t>>(dp, "s_device_element_connectors::r_device_element_connectors");
        waitset.attach_condition(dds::sub::cond::ReadCondition(
            r_device_element_connectors,
            dds::sub::status::DataState::any(),
            std::bind(&Task_Controller_dp::r_device_element_connectors_read_callback, this)));
        if (r_device_element_connectors == dds::core::null)
        {
            throw std::runtime_error("Looking up r_device_element_connectors failed. Are all necessary DDS-XML files loaded?");
        }
        r_device_element_bbox = rti::sub::find_datareader_by_name<dds::sub::DataReader<DeviceInformation::BoundingBox_t>>(dp, "s_device_element_bbox::r_device_element_bbox");
        waitset.attach_condition(dds::sub::cond::ReadCondition(
            r_device_element_bbox,
            dds::sub::status::DataState::any(),
            std::bind(&Task_Controller_dp::r_device_element_bbox_read_callback, this)));
        if (r_device_element_bbox == dds::core::null)
        {
            throw std::runtime_error("Looking up r_device_element_bbox failed. Are all necessary DDS-XML files loaded?");
        }
        r_control_handling_capabilities = rti::sub::find_datareader_by_name<dds::sub::DataReader<Actuation::ControlHandlingCapabilities_t>>(dp, "s_control_handling_capabilities::r_control_handling_capabilities");
        waitset.attach_condition(dds::sub::cond::ReadCondition(
            r_control_handling_capabilities,
            dds::sub::status::DataState::any(),
            std::bind(&Task_Controller_dp::r_control_handling_capabilities_read_callback, this)));
        if (r_control_handling_capabilities == dds::core::null)
        {
            throw std::runtime_error("Looking up r_control_handling_capabilities failed. Are all necessary DDS-XML files loaded?");
        }
        w_control_handling_values = rti::pub::find_datawriter_by_name<dds::pub::DataWriter<Actuation::ControlHandlingValues_t>>(dp, "p_control_handling_values::w_control_handling_values");
        if (w_control_handling_values == dds::core::null)
        {
            throw std::runtime_error("Looking up w_control_handling_values failed. Are all necessary DDS-XML files loaded?");
        }
        r_control_handling_values = rti::sub::find_datareader_by_name<dds::sub::DataReader<Actuation::ControlHandlingValues_t>>(dp, "s_control_handling_values::r_control_handling_values");
        waitset.attach_condition(dds::sub::cond::ReadCondition(
            r_control_handling_values,
            dds::sub::status::DataState::any(),
            std::bind(&Task_Controller_dp::r_control_handling_values_read_callback, this)));
        if (r_control_handling_values == dds::core::null)
        {
            throw std::runtime_error("Looking up r_control_handling_values failed. Are all necessary DDS-XML files loaded?");
        }
        r_gnss = rti::sub::find_datareader_by_name<dds::sub::DataReader<GNSS::PositionData_t>>(dp, "s_gnss::r_gnss");
        waitset.attach_condition(dds::sub::cond::ReadCondition(
            r_gnss,
            dds::sub::status::DataState::any(),
            std::bind(&Task_Controller_dp::r_gnss_read_callback, this)));
        if (r_gnss == dds::core::null)
        {
            throw std::runtime_error("Looking up r_gnss failed. Are all necessary DDS-XML files loaded?");
        }
        r_vehicle = rti::sub::find_datareader_by_name<dds::sub::DataReader<Vehicle::VehicleData_t>>(dp, "s_vehicle::r_vehicle");
        waitset.attach_condition(dds::sub::cond::ReadCondition(
            r_vehicle,
            dds::sub::status::DataState::any(),
            std::bind(&Task_Controller_dp::r_vehicle_read_callback, this)));
        if (r_vehicle == dds::core::null)
        {
            std::cout << "Whattt" << std::endl;
            throw std::runtime_error("Looking up r_vehicle failed. Are all necessary DDS-XML files loaded?");
        }
        w_service_discovery = rti::pub::find_datawriter_by_name<dds::pub::DataWriter<DeviceInformation::ServiceDiscovery_t>>(dp, "p_service_discovery::w_service_discovery");
        if (w_service_discovery == dds::core::null)
        {
            throw std::runtime_error("Looking up w_service_discovery failed. Are all necessary DDS-XML files loaded?");
        }

        r_service_discovery = rti::sub::find_datareader_by_name<dds::sub::DataReader<DeviceInformation::ServiceDiscovery_t>>(dp, "s_service_discovery::r_service_discovery");
        if (r_service_discovery == dds::core::null)
        {
            throw std::runtime_error("Looking up r_service_discovery failed. Are all necessary DDS-XML files loaded?");
        }

        waitset.attach_condition(dds::sub::cond::ReadCondition(
            r_service_discovery,
            dds::sub::status::DataState::any(),
            std::bind(&Task_Controller_dp::r_service_discovery_read_callback, this)));

        w_service_discovery.write(DeviceInformation::ServiceDiscovery_t(0,
            dds::core::optional<uint8_t>(),
            1,
            dds::core::optional<uint8_t>(),
            dds::core::optional<uint8_t>())
        );
    }

    void Task_Controller_dp::start_logic()
    {
        logic_thread = std::thread(&Task_Controller_dp::logic, this);
    }

    void Task_Controller_dp::stop_logic()
    {
        stop_requested = true;
        std::cout << "Application shutdown initiated..." << std::endl;
        logic_thread.join();
    }

    bool Task_Controller_dp::logic_running()
    {
        return logic_thread.joinable();
    }

    void Task_Controller_dp::send(const Actuation::ControlHandlingValues_t& msg)
    {
        w_control_handling_values.write(msg);
    }

    void Task_Controller_dp::logic()
    {
        while (!stop_requested)
        {
            // runs the handlers of the active conditions, waits for up to 1 second.
            waitset.dispatch(dds::core::Duration(1));
        }
    }

    void Task_Controller_dp::r_diagnostics_read_callback()
    {
        for (auto msg : r_diagnostics.take())
        {
            if (msg.info().valid())
            {
                std::cout << "Device Element " << msg.data().element_ref().name() << "." << msg.data().element_ref().element_id() << ": "
                    << msg.data().diagnostic_type() << ": "
                    << msg.data().diagnostic_code() << ": "
                    << msg.data().message() << std::endl;
            }
        }
    }

    void Task_Controller_dp::r_device_element_read_callback()
    {
        for (auto msg : r_device_element.take())
        {
            if (msg.info().valid())
            {
                std::cout << "New Device Element connected." << std::endl;
                std::cout << "Reference: " << msg.data().element_ref().name() << "." << msg.data().element_ref().element_id() << std::endl;
                device_elements.insert(msg.data());
            }
            else
            {
                if ((msg.info().state().instance_state() & dds::sub::status::InstanceState::not_alive_mask()).any())
                {
                    DeviceInformation::DeviceElement_t not_alive_device_element_keys;
                    r_device_element.key_value(not_alive_device_element_keys, msg.info().instance_handle());
                    auto search = device_elements.find(not_alive_device_element_keys);
                    if (search != device_elements.end())
                    {
                        auto not_alive_device_element = *search;
                        device_elements.erase(not_alive_device_element);
                        std::cout << "Device Element " << not_alive_device_element.name()
                            << " with reference " << not_alive_device_element.element_ref().name() << "." << not_alive_device_element.element_ref().element_id()
                            << " disconnected" << std::endl;
                    }
                }
            }
        }
    }

    void Task_Controller_dp::r_device_element_connectors_read_callback()
    {
        for (auto msg : r_device_element_connectors.take())
        {
            if (msg.info().valid())
            {
                // Do things
            }
        }
    }

    void Task_Controller_dp::r_device_element_bbox_read_callback()
    {
        for (auto msg : r_device_element_bbox.take())
        {
            if (msg.info().valid())
            {
                // Do things
            }
        }
    }

    void Task_Controller_dp::r_control_handling_capabilities_read_callback()
    {
        for (auto msg : r_control_handling_capabilities.take())
        {
            if (msg.info().valid())
            {
                const auto& element_ref = msg.data().element_ref();
                std::cout << "Device element with reference: " << element_ref.name() << "." << element_ref.element_id();
                std::cout << " announced the following handling capabilities: [not implemented]" << std::endl;
                // TODO: nice debug-print for enums
            }
            else
            {
                // Do something here
                std::cout << "Received message not valid. Implementation of Error-Handling pending." << std::endl;
            }
        }
    }

    void Task_Controller_dp::r_control_handling_values_read_callback()
    {
        for (auto msg : r_control_handling_values.take())
        {
            if (msg.info().valid())
            {
                const auto& element_ref = msg.data().element_ref();

                std::cout << "Device element with reference: " << element_ref.name() << "." << element_ref.element_id();
                std::cout << " announced new handling-value: " << msg.data().value() << std::endl;
                std::cout << "For feature [not implemented]" << std::endl;
                // TODO: nice debug-print for enums
            }
            else
            {
                // Do something here
                std::cout << "Received message not valid. Implementation of Error-Handling pending.";
            }
        }
    }
    void Task_Controller_dp::r_gnss_read_callback()
    {
        for (auto msg : r_gnss.take()) {
            if (msg.info().valid()) {
                std::cout << "[Name: " << msg.data().NAME() << ", "
                    << "SID: " << (int)msg.data().SID() << ", "
                    << "PositionDate: " << msg.data().PositionDate() << ", "
                    << "PositionTime: " << msg.data().PositionTime() << ", "
                    << "Lat: " << msg.data().Lat().value() << ", "
                    << "Lon: " << msg.data().Lon().value() << ", "
                    << "Alt: " << msg.data().Alt().value() << ", "
                    << "TypeOfSystem: " << msg.data().TypeOfSystem() << ", "
                    << "Method: " << (int)msg.data().Method().value() << ", "
                    << "NumOfSVs: " << (int)msg.data().NumOfSVs().value() << ", "
                    << "HDOP: " << msg.data().HDOP() << ", "
                    << "PDOP: " << msg.data().PDOP() << ", "
                    << "GeoidalSeparation: " << msg.data().GeoidalSeparation() << ", "
                    << "ReferenceStation: " << msg.data().ReferenceStation() << "]" << std::endl;
            }
            else {
                std::cout << "Received message not valid. Implementation of Error-Handling pending." << std::endl;
            }
        }
    }
    void Task_Controller_dp::r_vehicle_read_callback()
    {
        for (auto msg : r_vehicle.take()) {
            if (msg.info().valid()) {
                std::cout << "[ID: " << msg.data().ID() << ", "
                    << "Engine: " << msg.data().Engine() << ", "
                    << "Dynamics: " << msg.data().Dynamics() << "]" << std::endl;
            }
            else {
                std::cout << "Received message not valid. Implementation of Error-Handling pending." << std::endl;
            }
        }
    }

    void Task_Controller_dp::r_service_discovery_read_callback()
    {
        for (auto msg : r_service_discovery.take())
        {
            if (msg.info().valid())
            {
                // Do some check for version matching
                std::cout << "Got service discovery msg" << std::endl;
            }
        }
    }
}
