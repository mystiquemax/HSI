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
#include <dds/core/Optional.hpp>

#include "Sprayer_dp.hpp"
namespace Implement
{
	Sprayer_dp::Sprayer_dp(
		const unsigned& number_sections,
		const DeviceInformation::DeviceElement_t& device_info,
		const std::string& domain_participant_name)
		: Generic_ControlHandlingDeviceElement_dp(device_info, domain_participant_name, false),
		tank({ "Sprayer_Tank", DeviceInformation::ElementReference_t(device_info.element_ref().name(), 1),
			device_info.element_ref()})
	{
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
			std::bind(&Sprayer_dp::r_service_discovery_read_callback, this)));

		w_service_discovery.write(DeviceInformation::ServiceDiscovery_t(device_info.element_ref().name(), 1,
			dds::core::optional<uint8_t>(),
			dds::core::optional<uint8_t>(), 
			dds::core::optional<uint8_t>())
		);

		w_ddi_linking.write(Actuation::ControlHandlingCapabilities_t(device_info.element_ref(),
			Actuation::HandlingGroup_e::working_height, 42, this->unit_working_height));

		for (unsigned i = 2; i <= number_sections+1; i++)
		{
			DeviceInformation::DeviceElement_t info_section(std::string("Section_") + std::to_string(i-1), device_info.element_ref(), device_info.parent_ref());
			sections.push_back(std::make_unique<Section_dp>(info_section));
		}
		// The sprayer is now ready and notifies all listeners of its existance
		notify_device_ready();
	}
	void Sprayer_dp::start_logic()
	{
		this->logic_thread = std::thread(&Sprayer_dp::logic, this);
		
		this->tank.start_logic();
		for (unsigned i = 0; i < sections.size(); i++)
		{
			sections.at(i)->start_logic();
		}
	}
	void Sprayer_dp::stop_logic()
	{
		std::cout << "Application shutdown initiated..." << std::endl;
		stop_requested = true;
		tank.stop_logic();
		for (auto& section : sections)
		{
			section->stop_logic();
		}
	}
	void Sprayer_dp::join_logic()
	{
		tank.join_logic();
		for (auto& section : sections)
		{
			section->join_logic();
		}
		logic_thread.join();
	}
	bool Sprayer_dp::logic_running() const
	{
		bool is_sections_joinable = true;
		for (const auto& section : sections)
		{
			is_sections_joinable &= section->logic_running();
		}
		return logic_thread.joinable() && is_sections_joinable && tank.logic_running();
	}
	void Sprayer_dp::logic()
	{
		auto last_loop_time = std::chrono::steady_clock::now();
		while (!stop_requested)
		{
			if (std::fabs(actual_height - setpoint_height) > 1e-2)
			{
				actual_height += refresh_rate * (setpoint_height - actual_height) / time_constant;
				w_pd_values.write(Actuation::ControlHandlingValues_t(device_info.element_ref(),
					Actuation::HandlingFeature_e::actual,
					Actuation::HandlingGroup_e::working_height,
					actual_height,
					unit_working_height));
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
	void Sprayer_dp::r_pd_values_read_callback()
	{
		for (auto msg : r_pd_values.take())
		{
			if (msg.info().valid())
			{
				if (msg.data().element_ref() != device_info.element_ref())
				{
					throw std::runtime_error("Message filtering not in place");
				}
				else if (msg.data().handling_group() == Actuation::HandlingGroup_e::working_height && msg.data().handling_feature() == Actuation::HandlingFeature_e::setpoint)
				{
					if (msg.data().unit() != unit_working_height)
					{
						w_diagnostics.write(Diagnostics::Diagnostic_t(device_info.element_ref(),
							Diagnostics::DiagnosticCode_e::unit_mismatch,
							Diagnostics::DiagnosticType_e::error_recoverable,
							"The unit of Sprayer_dp's working height is controlled in meters!"));
					}
					else
					{
						std::cout << device_info.name() << " Received new setpoint-value: " << msg.data().value() << std::endl;
						setpoint_height = msg.data().value();
					}
				}
				else
				{
					// We don't have the received handling feature/group
					w_diagnostics.write(Diagnostics::Diagnostic_t(device_info.element_ref(),
						Diagnostics::DiagnosticCode_e::handling_group_mismatch,
						Diagnostics::DiagnosticType_e::error_recoverable,
						"Sprayer_dp can only control working_height!"));
				}
			}
			else
			{
				std::cout << device_info.name() << " Received message was not valid." << std::endl;
			}
		}
	}

	void Sprayer_dp::r_service_discovery_read_callback()
	{
		for (auto msg : r_service_discovery.take())
		{
			if (msg.info().valid())
			{
				std::cout << "Got service discovery msg" << std::endl;
			}
		}
	}
}
