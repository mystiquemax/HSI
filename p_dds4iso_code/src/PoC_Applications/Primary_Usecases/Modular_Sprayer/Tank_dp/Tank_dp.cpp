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
#include "Tank_dp.hpp"
namespace Implement
{
	Tank_dp::Tank_dp(const DeviceInformation::DeviceElement_t &device_info,
		const std::string& domain_participant_name)
		: Generic_ControlHandlingDeviceElement_dp(device_info, domain_participant_name)
	{
		w_ddi_linking.write(Actuation::ControlHandlingCapabilities_t(device_info.element_ref(),
			Actuation::HandlingGroup_e::fill_level, 42, this->unit_fill_level));
		w_ddi_linking.write(Actuation::ControlHandlingCapabilities_t(device_info.element_ref(),
			Actuation::HandlingGroup_e::flow_rate, 42, this->unit_flow_rate));
	}
    void Tank_dp::logic()
    {
		auto last_loop_time = std::chrono::steady_clock::now();
		while (!stop_requested)
		{
			curr_fill_level -= flow_rate * std::chrono::duration_cast<std::chrono::seconds>(refresh_rate).count();
			if (curr_fill_level < 0)
			{
				curr_fill_level = 0;
			}
			w_pd_values.write(Actuation::ControlHandlingValues_t(device_info.element_ref(),
				Actuation::HandlingFeature_e::actual,
				Actuation::HandlingGroup_e::fill_level,
				curr_fill_level,
				unit_fill_level));
			w_pd_values.write(Actuation::ControlHandlingValues_t(device_info.element_ref(),
				Actuation::HandlingFeature_e::actual,
				Actuation::HandlingGroup_e::flow_rate,
				flow_rate,
				unit_flow_rate));
			// Simulated fill-up
			// TODO: Maybe introduce some alarm if fill_level is below alarm level?
			curr_fill_level = max_fill_level;
			for (auto loop_period = std::chrono::steady_clock::now() - last_loop_time;
				loop_period < refresh_rate;
				loop_period = std::chrono::steady_clock::now() - last_loop_time)
			{
				waitset.dispatch(dds::core::Duration(refresh_rate - loop_period));
			}
			last_loop_time = std::chrono::steady_clock::now();
		}
    }
	void Tank_dp::r_pd_values_read_callback()
	{
		for (auto msg : r_pd_values.take())
		{
			if (msg.info().valid())
			{
				if (msg.data().element_ref() != device_info.element_ref())
				{
					throw std::runtime_error("Message filtering not in place");
				}
				if (msg.data().handling_group() == Actuation::HandlingGroup_e::fill_level)
				{
					if (msg.data().unit() != unit_fill_level)
					{
						w_diagnostics.write(Diagnostics::Diagnostic_t(device_info.element_ref(),
							Diagnostics::DiagnosticCode_e::unit_mismatch,
							Diagnostics::DiagnosticType_e::error_recoverable,
							"Missmatch in units when setting tank fill_level"));
					}
					// Control total fill level (e.g. simulated fill-up)
					switch (msg.data().handling_feature())
					{
					case Actuation::HandlingFeature_e::minimum:
						this->alarm_fill_level = msg.data().value();
						break;
					case Actuation::HandlingFeature_e::actual:
						break;
					default: 
						w_diagnostics.write(Diagnostics::Diagnostic_t(device_info.element_ref(),
							Diagnostics::DiagnosticCode_e::handling_group_mismatch,
							Diagnostics::DiagnosticType_e::error_recoverable,
							"Tank fill_level only accepts minimum values!"));
					}
				}
				else if (msg.data().handling_group() == Actuation::HandlingGroup_e::flow_rate)
				{
					if (msg.data().unit() != unit_flow_rate)
					{
						w_diagnostics.write(Diagnostics::Diagnostic_t(device_info.element_ref(),
							Diagnostics::DiagnosticCode_e::unit_mismatch,
							Diagnostics::DiagnosticType_e::error_recoverable,
							"Missmatch in units when setting tank flow_rate"));
					}
					switch (msg.data().handling_feature())
					{
					case Actuation::HandlingFeature_e::setpoint:
						this->flow_rate = msg.data().value();
						break;
					case Actuation::HandlingFeature_e::actual:
						break;
					default: 
						w_diagnostics.write(Diagnostics::Diagnostic_t(device_info.element_ref(),
							Diagnostics::DiagnosticCode_e::handling_group_mismatch,
							Diagnostics::DiagnosticType_e::error_recoverable,
							"Tank flow_rate only accepts setpoint values!"));
					}
				}
				else
				{
					w_diagnostics.write(Diagnostics::Diagnostic_t(device_info.element_ref(),
						Diagnostics::DiagnosticCode_e::handling_group_mismatch,
						Diagnostics::DiagnosticType_e::error_recoverable,
						"Tank only has properties fill_level and flow_rate"));
				}
			}
			else
			{
				std::cout << device_info.name() << " Received message was not valid." << std::endl;
			}
		}
	}
}
