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
#include <dds/topic/find.hpp>
#include "Generic_ControlHandlingDeviceElement_dp.hpp"
namespace Implement
{
    Generic_ControlHandlingDeviceElement_dp::Generic_ControlHandlingDeviceElement_dp(const DeviceInformation::DeviceElement_t &device_info,
		const std::string& domain_participant_name,
        const bool& do_notify_device_ready)
        : Generic_DeviceElement_dp(device_info, do_notify_device_ready, domain_participant_name)
    {
		// Filter parameters for f_device_element
		std::vector<std::string> filter_params{ std::to_string(device_info.element_ref().name()), std::to_string(device_info.element_ref().element_id()) };
        
		w_ddi_linking = rti::pub::find_datawriter_by_name<dds::pub::DataWriter<Actuation::ControlHandlingCapabilities_t>>(dp, "p_ddi_linking::w_ddi_linking");
        if (w_ddi_linking == dds::core::null)
        {
            throw std::runtime_error("Looking up w_ddi_linking failed. Are all necessary DDS-XML files loaded?");
        }
        w_pd_values = rti::pub::find_datawriter_by_name<dds::pub::DataWriter<Actuation::ControlHandlingValues_t>>(dp, "p_pd_values_best_effort::w_pd_values_best_effort");
        if (w_pd_values == dds::core::null)
        {
            throw std::runtime_error("Looking up w_pd_values failed. Are all necessary DDS-XML files loaded?");
        }
        r_pd_values = rti::sub::find_datareader_by_name<dds::sub::DataReader<Actuation::ControlHandlingValues_t>>(dp, "s_pd_values_best_effort::r_pd_values_best_effort");
        waitset.attach_condition(dds::sub::cond::ReadCondition(
            r_pd_values,
            dds::sub::status::DataState::any(),
            std::bind(&Generic_ControlHandlingDeviceElement_dp::r_pd_values_read_callback, this)));
        if (r_pd_values == dds::core::null)
        {
            throw std::runtime_error("Looking up r_pd_values failed. Are all necessary DDS-XML files loaded?");
        }
		dds::topic::find<dds::topic::ContentFilteredTopic<Actuation::ControlHandlingValues_t>>(dp, r_pd_values.topic_description().name()).filter_parameters(filter_params.begin(), filter_params.end());
    }
    void Generic_ControlHandlingDeviceElement_dp::logic()
    {
        while (!stop_requested)
        {
            // runs the handlers of the active conditions, waits for up to 1 second.
            waitset.dispatch(dds::core::Duration(1));
        }
    }
    void Generic_ControlHandlingDeviceElement_dp::r_pd_values_read_callback()
    {
        for (auto msg : r_pd_values.take())
        {
            if (msg.info().valid())
            {
				// Do sth
			}
        }
    }
}
