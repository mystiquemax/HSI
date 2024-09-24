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

#ifndef Implement_Sprayer_dp_HPP
#define Implement_Sprayer_dp_HPP

#include <chrono>

#include <dds/core/cond/WaitSet.hpp>
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>

#include "HSI_Standard_topics.hpp"
#include "Generic_ControlHandlingDeviceElement_dp.hpp"
#include "../Tank_dp/Tank_dp.hpp"
#include "../Section_dp/Section_dp.hpp"

using namespace std::chrono_literals;

namespace Implement
{
	class Sprayer_dp : public Generic_ControlHandlingDeviceElement_dp
	{
	public:
		Sprayer_dp(
			const unsigned& number_sections,
			const DeviceInformation::DeviceElement_t& device_info,
			const std::string& domain_participant_name = "TUM_Sprayer::TUM_sprayer_dp");

		void start_logic() override;
		void stop_logic() override;
		void join_logic() override;
		bool logic_running() const override;

	protected:
		void logic() override;
		void r_pd_values_read_callback() override;
		virtual void r_service_discovery_read_callback();

	private:
		Tank_dp tank;

		// TODO: One shouldn't need to use pointers here
		std::vector<std::unique_ptr<Section_dp>> sections;

		double setpoint_height = 0;
		double actual_height = 0;

		std::chrono::seconds refresh_rate = 1s;
		std::chrono::seconds time_constant = 4s;

		const Common::Unit_t unit_working_height{ Common::Unit_e::m, Common::Unit_e::none };

		dds::pub::DataWriter<DeviceInformation::ServiceDiscovery_t> w_service_discovery = dds::core::null;
		dds::sub::DataReader<DeviceInformation::ServiceDiscovery_t> r_service_discovery = dds::core::null;

		const uint8_t TC_CLIENT_VERSION = 1;
	};
}

#endif
