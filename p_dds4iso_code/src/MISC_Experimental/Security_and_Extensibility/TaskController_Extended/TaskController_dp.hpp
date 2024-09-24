// MIT License
// 
// Copyright (c) 2024 Technical University of Munich
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

#ifndef Tractor_TaskController_dp_HPP
#define Tractor_TaskController_dp_HPP

#include <set>
#include <atomic>

#include <dds/core/cond/WaitSet.hpp>
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>

#include "../../data_types/HSI_Standard_topics.hpp"
#include "../dp_utils.hpp"

namespace Tractor
{
    class TaskController_dp
    {
    public:
        TaskController_dp(const std::string& domain_participant_name = "Generic_TcServer::Generic_TcServer_dp");
        void start_logic();
        void stop_logic();
        bool logic_running();
		void send(const Actuation::ControlHandlingValues_t &msg);
		const std::set<DeviceInformation::DeviceElement_t, dp_utils::device_element_ref_cmp> &get_device_elements() { return device_elements; };

    protected:        
        virtual void r_diagnostics_read_callback();
        virtual void r_device_element_read_callback();
        virtual void r_device_element_connectors_read_callback();
        virtual void r_device_element_bbox_read_callback();
        virtual void r_control_handling_capabilities_read_callback();
        virtual void r_control_handling_values_read_callback();
        virtual void r_gnss_read_callback();
        virtual void r_vehicle_read_callback();
        virtual void r_service_discovery_read_callback();

        dds::domain::DomainParticipant dp = dds::core::null;
        dds::sub::DataReader<Diagnostics::Diagnostic_t> r_diagnostics = dds::core::null;
        dds::sub::DataReader<DeviceInformation::DeviceElement_t> r_device_element = dds::core::null;
        dds::sub::DataReader<DeviceInformation::ConnectorList_t> r_device_element_connectors = dds::core::null;
        dds::sub::DataReader<DeviceInformation::BoundingBox_t> r_device_element_bbox = dds::core::null;
        dds::sub::DataReader<Actuation::ControlHandlingCapabilities_t> r_control_handling_capabilities = dds::core::null;
        dds::pub::DataWriter<Actuation::ControlHandlingValues_t> w_control_handling_values = dds::core::null;
        dds::sub::DataReader<Actuation::ControlHandlingValues_t> r_control_handling_values = dds::core::null;
        dds::sub::DataReader<GNSS::PositionData_t> r_gnss = dds::core::null;
        dds::sub::DataReader<Vehicle::VehicleData_t> r_vehicle = dds::core::null;
        dds::pub::DataWriter<DeviceInformation::ServiceDiscovery_extended_t> w_service_discovery = dds::core::null;
        dds::sub::DataReader<DeviceInformation::ServiceDiscovery_extended_t> r_service_discovery = dds::core::null;
        
        volatile std::atomic_bool stop_requested = false;
        std::thread logic_thread;
        dds::core::cond::WaitSet waitset;
        virtual void logic();

		std::set<DeviceInformation::DeviceElement_t, dp_utils::device_element_ref_cmp> device_elements;

    private:
        const rti::core::bounded_sequence<int8_t, 256> hsi_conformity_certificate = rti::core::bounded_sequence<int8_t, 256>( 256, 3 ); // Toy-example for certificate 
    };
}

#endif
