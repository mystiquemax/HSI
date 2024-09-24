// MIT License
// 
// Copyright (c) 2024 Technical University of Munich
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

#include "TaskController_dp.hpp"
#include "../app_utils.hpp"

using namespace std::chrono_literals;

int main()
{
	// Catch ctr+x to allow for graceful program termination
	application::setup_signal_handlers();
    
    rti::core::QosProviderParams provider_params;
    provider_params.url_profile({"src/Applications/Tractor/TaskController_Extended/HSI_Standard_topics_extended.xml", std::string(PATH_INFORMATION_MODEL)+"/HSI_generic_TcServer.xml"});
    rti::core::default_qos_provider_params(provider_params);
    rti::domain::register_type<DeviceInformation::DeviceElement_t>("DeviceElement_t");
    rti::domain::register_type<DeviceInformation::ConnectorList_t>("ConnectorList_t");
    rti::domain::register_type<DeviceInformation::BoundingBox_t>("BoundingBox_t");
    rti::domain::register_type<DeviceInformation::ServiceDiscovery_extended_t>("ServiceDiscovery_extended_t");
    rti::domain::register_type<Actuation::ControlHandlingCapabilities_t>("ControlHandlingCapabilities_t");
    rti::domain::register_type<Actuation::ControlHandlingValues_t>("ControlHandlingValues_t");
    rti::domain::register_type<Common::OnOff_t>("OnOff_t");
    rti::domain::register_type<Diagnostics::Diagnostic_t>("Diagnostic_t");
    rti::domain::register_type<GNSS::PositionData_t>("PositionData_t");
    rti::domain::register_type<Vehicle::VehicleData_t>("VehicleData_t");
    Tractor::TaskController_dp task_controller_dp;
    task_controller_dp.start_logic();
    
    while (application::run_application && task_controller_dp.logic_running())
    {
        std::string command;
        std::cin >> command;

        if (command == "set")
        {
            std::string target_str;
            std::cin >> target_str;
            std::string handling_group_string;
            std::cin >> handling_group_string;
            std::string value_str;
            std::cin >> value_str;
  
            double value = std::stod(value_str);

            if (target_str == "all")
            {
                if (task_controller_dp.get_device_elements().empty())
                {
                    std::cout << "No device elements attached" << std::endl;
                }
                for (auto device_element : task_controller_dp.get_device_elements())
                {
                    task_controller_dp.send(Actuation::ControlHandlingValues_t(
                        device_element.element_ref(),
                        Actuation::HandlingFeature_e::setpoint,
                        Actuation::HandlingGroup_e::application_rate,
                        value,
                        Common::Unit_t()));
                    std::cout << "sent setpoint " << value
                        << " to device element with NAME " << device_element.element_ref().name()
                        << ", element_id " << device_element.element_ref().element_id()
                        << std::endl;
                }
            }
            else
            {
                std::string address_part;
                auto sep_idx = target_str.find('.');
                auto name = std::stoi(target_str.substr(0, sep_idx));
                auto element_id = std::stoi(target_str.substr(sep_idx + 1));

                if (handling_group_string == "application_rate")
                {
                    task_controller_dp.send(Actuation::ControlHandlingValues_t(
                        DeviceInformation::ElementReference_t(name, element_id),
                        Actuation::HandlingFeature_e::setpoint,
                        Actuation::HandlingGroup_e::application_rate,
                        value,
                        Common::Unit_t(Common::Unit_e::kg, Common::Unit_e::m_2)));
                    std::cout << "sent setpoint " << value << " to device element with NAME " << name << ", element_id " << element_id << std::endl;
                }
                else if (handling_group_string == "working_height")
                {
                    task_controller_dp.send(Actuation::ControlHandlingValues_t(
                        DeviceInformation::ElementReference_t(name, element_id),
                        Actuation::HandlingFeature_e::setpoint,
                        Actuation::HandlingGroup_e::working_height,
                        value,
                        Common::Unit_t(Common::Unit_e::m, Common::Unit_e::none)));
                    std::cout << "sent setpoint " << value << " to device element with NAME " << name << ", element_id " << element_id << std::endl;
                }
                else
                {
                    std::cout << "Give either \"application_rate\" or \"working_height\" as handling group string!" << std::endl;
                }
            }
        }
        else
        {
            std::cout << "command not implemented: " << command << std::endl;
        }
    }


	task_controller_dp.stop_logic();
}
