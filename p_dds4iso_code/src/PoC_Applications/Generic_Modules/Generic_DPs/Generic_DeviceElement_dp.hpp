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


#ifndef Implement_DeviceElement_dp_HPP
#define Implement_DeviceElement_dp_HPP
#include <atomic>
#include <set>
#include <dds/core/cond/WaitSet.hpp>
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include "HSI_Standard_topics.hpp"

namespace Implement
{
    class Generic_DeviceElement_dp
    {
    public:
        Generic_DeviceElement_dp(const DeviceInformation::DeviceElement_t &device_info,
            const bool& do_notify_device_ready,
			const std::string& domain_participant_name = "Generic_Implement::Generic_DeviceElement_dp");
        virtual void start_logic();
        virtual void stop_logic();
        virtual bool logic_running() const;
		virtual void join_logic();
    protected:        
        virtual void r_ddop_hierarchy_read_callback();
        virtual void notify_device_ready();
        dds::domain::DomainParticipant dp = dds::core::null;
        dds::sub::DataReader<DeviceInformation::DeviceElement_t> r_ddop_hierarchy = dds::core::null;
        dds::pub::DataWriter<Diagnostics::Diagnostic_t> w_diagnostics = dds::core::null;
        dds::pub::DataWriter<DeviceInformation::DeviceElement_t> w_ddop_hierarchy = dds::core::null;
        volatile std::atomic_bool stop_requested = false;
        std::thread logic_thread;
        dds::core::cond::WaitSet waitset;
        virtual void logic();
		const DeviceInformation::DeviceElement_t device_info;
    };
}
#endif
