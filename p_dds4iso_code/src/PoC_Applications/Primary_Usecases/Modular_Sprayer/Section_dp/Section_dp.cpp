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
#include "Section_dp.hpp"
namespace Implement
{
	Section_dp::Section_dp(const DeviceInformation::DeviceElement_t &device_info,
		const std::string& domain_participant_name)
		: Generic_ControlHandlingDeviceElement_dp(device_info,domain_participant_name)
	{
		w_ddi_linking.write(Actuation::ControlHandlingCapabilities_t(device_info.element_ref(),
			Actuation::HandlingGroup_e::application_rate, 42, unit_application_rate));
	}
    void Section_dp::logic()
    {
		auto last_loop_time = std::chrono::steady_clock::now();
		while (!stop_requested)
		{
			if (std::fabs(actual_application_rate - setpoint_application_rate) > 1e-2)
			{
				actual_application_rate += refresh_rate * (setpoint_application_rate - actual_application_rate) / time_constant;
				w_pd_values.write(Actuation::ControlHandlingValues_t(device_info.element_ref(),
					Actuation::HandlingFeature_e::actual,
					Actuation::HandlingGroup_e::application_rate,
					actual_application_rate,
					unit_application_rate));
			}
			for (auto loop_period = std::chrono::steady_clock::now() - last_loop_time;
				loop_period < refresh_rate;
				loop_period = std::chrono::steady_clock::now() - last_loop_time)
			{
				waitset.dispatch(dds::core::Duration(refresh_rate - loop_period));
			}
			last_loop_time = std::chrono::steady_clock::now();
		}
	}
	void Section_dp::r_pd_values_read_callback()
	{
		for (auto msg : r_pd_values.take())
		{
			if (msg.info().valid())
			{
				if (msg.data().element_ref() != device_info.element_ref())
				{
					throw std::runtime_error("Message filtering not in place");
				}
				else if (msg.data().handling_group() == Actuation::HandlingGroup_e::application_rate && msg.data().handling_feature() == Actuation::HandlingFeature_e::setpoint)
				{
					if (msg.data().unit() != unit_application_rate)
					{
						w_diagnostics.write(Diagnostics::Diagnostic_t(device_info.element_ref(),
							Diagnostics::DiagnosticCode_e::unit_mismatch,
							Diagnostics::DiagnosticType_e::error_recoverable,
							"The unit of Section_dp's application_rate is controlled in kg/m^2!"));
					}
					else
					{
						std::cout << device_info.name() << " Received new setpoint-value: " << msg.data().value() << std::endl;
						setpoint_application_rate = msg.data().value();
					}
				}
				else
				{
					// We don't have the received handling feature/group
					w_diagnostics.write(Diagnostics::Diagnostic_t(device_info.element_ref(),
						Diagnostics::DiagnosticCode_e::handling_group_mismatch,
						Diagnostics::DiagnosticType_e::error_recoverable,
						"Section_dp can only control application_rate!"));
				}
			}
			else
			{
				std::cout << device_info.name() << " Received message was not valid." << std::endl;
			}
		}
    }
}
