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

#include "ControlHandlingDeviceElement_dp.hpp"
#include "DeviceElement_dp.hpp"
#include "Nozzle_dp.hpp"

#include "applications/app_utils.hpp"

using namespace std::chrono_literals;

int main(int argc, char *argv[])
{
	// Catch ctr+c to allow for graceful program termination
	application::setup_signal_handlers();

    rti::core::QosProviderParams provider_params;
    provider_params.url_profile({"../../../../InformationModel/HSI_Standard.xml", "../../../../InformationModel/HSI_Sprayer.xml"});
    rti::core::default_qos_provider_params(provider_params);
    rti::domain::register_type<DeviceInformation::DeviceElement_t>("DeviceElement_t");
    rti::domain::register_type<DeviceInformation::ConnectorList_t>("ConnectorList_t");
    rti::domain::register_type<DeviceInformation::BoundingBox_t>("BoundingBox_t");
    rti::domain::register_type<Actuation::ControlHandlingCapabilities_t>("ControlHandlingCapabilities_t");
    rti::domain::register_type<Actuation::ControlHandlingValues_t>("ControlHandlingValues_t");
    rti::domain::register_type<Common::OnOff_t>("OnOff_t");
    rti::domain::register_type<Diagnostics::Diagnostic_t>("Diagnostic_t");

    Implement::Nozzle_dp nozzle_dp(application::parse_device_info(argc, argv), DeviceInformation::BoundingBox_t(), {});
    nozzle_dp.start_logic();

    while (application::run_application)
    {
        // Do things, at least put thread to sleep
        std::this_thread::sleep_for(1s);
    }
	nozzle_dp.stop_logic();
    nozzle_dp.join_logic();
}
