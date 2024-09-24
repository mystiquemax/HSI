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


#ifndef Implement_Tank_dp_HPP
#define Implement_Tank_dp_HPP
#include <chrono>
#include <dds/core/cond/WaitSet.hpp>
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include "HSI_Standard_topics.hpp"
#include "Generic_ControlHandlingDeviceElement_dp.hpp"
using namespace std::chrono_literals;
namespace Implement
{
    class Tank_dp : public Generic_ControlHandlingDeviceElement_dp
    {
    public:
		Tank_dp(const DeviceInformation::DeviceElement_t &device_info,
			const std::string& domain_participant_name = "TUM_Sprayer::TUM_spray_tank_dp");
    protected:        
		void r_pd_values_read_callback() override;
        void logic() override;
		const double max_fill_level = 4;
		double curr_fill_level = max_fill_level;
		double alarm_fill_level = 1;
		double flow_rate = 0;
		std::chrono::seconds refresh_rate = 1s;
		std::chrono::seconds time_constant = 4s;
		Common::Unit_t unit_fill_level{ Common::Unit_e::m_3, Common::Unit_e::none };
		Common::Unit_t unit_flow_rate{ Common::Unit_e::m_3, Common::Unit_e::s };
    };
}
#endif
