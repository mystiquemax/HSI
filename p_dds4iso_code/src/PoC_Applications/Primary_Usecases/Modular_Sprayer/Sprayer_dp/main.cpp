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
#include <unordered_map>
#include <dds/core/QosProvider.hpp>

#include "Sprayer_dp.hpp"
#include "../app_utils.hpp"
using namespace std::chrono_literals;
namespace {
	constexpr unsigned NUMBER_SPRAYER_SECTIONS{ 4 };
}
int main()
{
	// Catch ctr+c to allow for graceful program termination
	application::setup_signal_handlers();
	rti::core::QosProviderParams provider_params;
	provider_params.url_profile({ std::string(PATH_INFORMATION_MODEL) + "/HSI_Standard_topics.xml"
				, std::string(PATH_INFORMATION_MODEL) + "/TUM_sprayer.xml" });
    rti::core::default_qos_provider_params(provider_params);
    rti::domain::register_type<DeviceInformation::Device_t>("Device_t");
    rti::domain::register_type<DeviceInformation::DeviceElement_t>("DeviceElement_t");
	rti::domain::register_type<DeviceInformation::ServiceDiscovery_t>("ServiceDiscovery_t"); 
    rti::domain::register_type<Actuation::ControlHandlingCapabilities_t>("ControlHandlingCapabilities_t");
    rti::domain::register_type<Actuation::ControlHandlingValues_t>("ControlHandlingValues_t");
    rti::domain::register_type<Common::OnOff_t>("OnOff_t");
    rti::domain::register_type<Diagnostics::Diagnostic_t>("Diagnostic_t");
	std::cout << "Starting" << std::endl;
	Implement::Sprayer_dp HSI_sprayer(NUMBER_SPRAYER_SECTIONS,
		DeviceInformation::DeviceElement_t("HSI_Sprayer", { 0,0 }, { 0,0 }));
	HSI_sprayer.start_logic();
	
	while (application::run_application)
	{
		// Do things, at least put thread to sleep
		std::this_thread::sleep_for(1s);
	}
	HSI_sprayer.stop_logic();
	HSI_sprayer.join_logic();
}
