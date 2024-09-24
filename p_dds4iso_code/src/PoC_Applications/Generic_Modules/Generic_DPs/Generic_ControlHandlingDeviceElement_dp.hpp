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


#ifndef Implement_ControlHandlingDeviceElement_dp_HPP
#define Implement_ControlHandlingDeviceElement_dp_HPP
#include <dds/core/cond/WaitSet.hpp>
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include "HSI_Standard_topics.hpp"
#include "Generic_DeviceElement_dp.hpp"
namespace Implement
{
    class Generic_ControlHandlingDeviceElement_dp : public Generic_DeviceElement_dp
    {
    public:
        Generic_ControlHandlingDeviceElement_dp(const DeviceInformation::DeviceElement_t &device_info,
			const std::string& domain_participant_name = "Generic_Implement::Generic_ControlHandlingDeviceElement_dp",
            const bool& do_notify_device_ready = true);
    protected:        
        virtual void r_pd_values_read_callback();
        dds::pub::DataWriter<Actuation::ControlHandlingCapabilities_t> w_ddi_linking = dds::core::null;
        dds::pub::DataWriter<Actuation::ControlHandlingValues_t> w_pd_values = dds::core::null;
        dds::sub::DataReader<Actuation::ControlHandlingValues_t> r_pd_values = dds::core::null;
        void logic() override;
    };
}
#endif
