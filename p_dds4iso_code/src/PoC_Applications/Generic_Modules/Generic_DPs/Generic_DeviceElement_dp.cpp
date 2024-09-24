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
#include <dds/domain/ddsdomain.hpp>
#include <dds/topic/find.hpp>
#include "Generic_DeviceElement_dp.hpp"
namespace Implement
{
	Generic_DeviceElement_dp::Generic_DeviceElement_dp(const DeviceInformation::DeviceElement_t& device_info,
		const bool& do_notify_device_ready,
		const std::string& domain_participant_name)
		: device_info(device_info)
	{
		// Filter parameters for f_parent_device_element
		std::vector<std::string> filter_params{ std::to_string(device_info.element_ref().name()), std::to_string(device_info.element_ref().element_id()) };
		auto default_provider = dds::core::QosProvider::Default();
		dp = default_provider.extensions().create_participant_from_config(domain_participant_name);
		// Ignore messages from ourselves on all topics
		dds::domain::ignore(dp, dp.instance_handle());
		r_ddop_hierarchy = rti::sub::find_datareader_by_name<dds::sub::DataReader<DeviceInformation::DeviceElement_t>>(dp, "s_ddop_hierarchy::r_ddop_hierarchy");
        waitset.attach_condition(dds::sub::cond::ReadCondition(
            r_ddop_hierarchy,
            dds::sub::status::DataState::any(),
            std::bind(&Generic_DeviceElement_dp::r_ddop_hierarchy_read_callback, this)));
        if (r_ddop_hierarchy == dds::core::null)
        {
            throw std::runtime_error("Looking up r_ddop_hierarchy failed. Are all necessary DDS-XML files loaded?");
        }
        w_diagnostics = rti::pub::find_datawriter_by_name<dds::pub::DataWriter<Diagnostics::Diagnostic_t>>(dp, "p_diagnostics::w_diagnostics");
        if (w_diagnostics == dds::core::null)
        {
            throw std::runtime_error("Looking up w_diagnostics failed. Are all necessary DDS-XML files loaded?");
        }
        w_ddop_hierarchy = rti::pub::find_datawriter_by_name<dds::pub::DataWriter<DeviceInformation::DeviceElement_t>>(dp, "p_ddop_hierarchy::w_ddop_hierarchy");
        if (w_ddop_hierarchy == dds::core::null)
        {
            throw std::runtime_error("Looking up w_ddop_hierarchy failed. Are all necessary DDS-XML files loaded?");
        }

		// Filter for device-elements that link to this element as parent (-> device-element children)
		dds::topic::find<dds::topic::ContentFilteredTopic<DeviceInformation::DeviceElement_t >>(dp, r_ddop_hierarchy.topic_description().name()).filter_parameters(filter_params.begin(), filter_params.end());
	
		if (do_notify_device_ready)
		{
			notify_device_ready();
		}
	}
	void Generic_DeviceElement_dp::start_logic()
	{
		logic_thread = std::thread(&Generic_DeviceElement_dp::logic, this);
	}
	void Generic_DeviceElement_dp::stop_logic()
	{
		stop_requested = true;
		std::cout << "Application shutdown initiated..." << std::endl;
	}
	void Generic_DeviceElement_dp::join_logic()
	{
		logic_thread.join();
	}
	bool Generic_DeviceElement_dp::logic_running() const
	{
		return logic_thread.joinable();
	}
	void Generic_DeviceElement_dp::logic()
	{
		while (!stop_requested)
		{
			// runs the handlers of the active conditions, waits for up to 1 second.
			waitset.dispatch(dds::core::Duration(1));
		}
	}
	void Generic_DeviceElement_dp::r_ddop_hierarchy_read_callback()
	{
		for (auto msg : r_ddop_hierarchy.take())
		{
			if (msg.info().valid() && msg.data().element_ref() != device_info.element_ref())
			{
				std::cout << device_info.name() << ": New Child Device Element connected. ";
				std::cout << "Reference: " << msg.data().element_ref().name() << "." << msg.data().element_ref().element_id() << std::endl;
			}
			else
			{
				// Disconnected child device element
				if ((msg.info().state().instance_state() & dds::sub::status::InstanceState::not_alive_mask()).any())
				{
					std::cout << "Child Device Element " << device_info.name()
						<< " disconnected" << std::endl;
				}
			}
		}
	}
	void Generic_DeviceElement_dp::notify_device_ready()
	{
		w_ddop_hierarchy.write(device_info);
		std::cout << "Device Element " << device_info.name() << std::endl
			<< "with element reference " << device_info.element_ref().name() << "." << device_info.element_ref().element_id() << std::endl
			<< "and parent reference " << device_info.parent_ref().name() << "." << device_info.parent_ref().element_id() << std::endl;
	}
}
