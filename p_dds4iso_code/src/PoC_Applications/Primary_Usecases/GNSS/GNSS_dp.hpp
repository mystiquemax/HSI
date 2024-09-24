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


#include <dds/core/cond/WaitSet.hpp>
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include "HSI_Standard_topics.hpp"
#include "HSI_Standard_topicsPlugin.hpp"
#include <thread>
namespace GNSS
{
	class GNSS_dp
	{
	    public:
			GNSS_dp(const std::string& domain_participant_name = "Generic_GNSS_Device::Generic_GNSS_Device_dp");
			void start_logic();
			void stop_logic();
			bool logic_running();
	    protected:
			dds::domain::DomainParticipant dp = dds::core::null;
			dds::pub::DataWriter<GNSS::PositionData_t> w_gnss = dds::core::null;
			volatile std::atomic_bool stop_requested = false;
			std::thread logic_thread;
			dds::core::cond::WaitSet waitset;
			void logic(double center_lat, double center_lon, double radius, float step);
	    private:
			const double PI = 3.14159265358979323846;
			Common::Date date();
			Common::Time time();
			::dds::core::optional< rti::core::bounded_sequence<GNSS::ReferenceStation, 10L>> reference_stations();
	};
}