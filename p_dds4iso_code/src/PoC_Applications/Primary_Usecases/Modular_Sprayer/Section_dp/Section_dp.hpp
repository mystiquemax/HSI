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


#ifndef Implement_Nozzle_dp_HPP
#define Implement_Nozzle_dp_HPP
#include <chrono>
#include <dds/core/cond/WaitSet.hpp>
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include "HSI_Standard_topics.hpp"
#include "Generic_ControlHandlingDeviceElement_dp.hpp"
using namespace std::chrono_literals;
namespace Implement
{
    class Section_dp : public Generic_ControlHandlingDeviceElement_dp
    {
    public:
        Section_dp(const DeviceInformation::DeviceElement_t &device_info,
			const std::string& domain_participant_name = "TUM_Sprayer::TUM_spray_section_dp");
    protected:     
		void logic() override;
		void r_pd_values_read_callback() override;
		double actual_application_rate = 0;
		double setpoint_application_rate = 0;
		std::chrono::seconds refresh_rate = 1s;
		std::chrono::seconds time_constant = 4s;
		const Common::Unit_t unit_application_rate{ Common::Unit_e::kg, Common::Unit_e::m_2 };
    };
}
#endif
