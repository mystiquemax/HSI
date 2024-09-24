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


#include "Vehicle_dp.hpp"
#include <dds/core/QosProvider.hpp>
#include <ctime>
Vehicle::Vehicle_dp::Vehicle_dp(const std::string& domain_participant_name)
{
	auto default_provider = dds::core::QosProvider::Default();
	dp = default_provider.extensions().create_participant_from_config(domain_participant_name);
	w_vehicle = rti::pub::find_datawriter_by_name<dds::pub::DataWriter<Vehicle::VehicleData_t>>(dp, "p_vehicle::w_vehicle");
	if (w_vehicle == dds::core::null)
	{
		std::cout << "Writer not found!" << std::endl;
		throw std::runtime_error("Looking up w_pd_values failed. Are all necessary DDS-XML files loaded?");
	}
}
void Vehicle::Vehicle_dp::start_logic()
{
	logic_thread = std::thread(&Vehicle::Vehicle_dp::logic, this);
}
void Vehicle::Vehicle_dp::stop_logic()
{
	stop_requested = true;
	std::cout << "Application shutdown initiated..." << std::endl;
	logic_thread.join();
}
bool Vehicle::Vehicle_dp::logic_running()
{
	return logic_thread.joinable();
}
Vehicle::Engine Vehicle::Vehicle_dp::engine()
{
	Vehicle::Engine sample;
	sample.RPM(1500);
	sample.Fuel_Consumption_Rate(8);
	sample.EGT(600);
	sample.Engine_Coolant_Temperature(83);
	sample.Intake_Air_Temperature(19);
	sample.Throttle_Position(43);
	sample.Engine_Load(67);
	sample.MAF(10);
	sample.Fuel_System_Pressure(21000);
	return sample;
}
::rti::core::bounded_sequence< ::Vehicle::Wheel_Speed, 4L> Vehicle::Vehicle_dp::wheels() {
	std::vector<::Vehicle::Wheel_Speed> ws;
	ws.push_back(::Vehicle::Wheel_Speed(Wheel::Front_Left, 40));
	ws.push_back(::Vehicle::Wheel_Speed(Wheel::Front_Right, 40));
	ws.push_back(::Vehicle::Wheel_Speed(Wheel::Rear_Left, 50));
	ws.push_back(::Vehicle::Wheel_Speed(Wheel::Rear_Right, 50));
	rti::core::bounded_sequence<::Vehicle::Wheel_Speed, 4L> boundedSequence(ws.begin(), ws.end());
	return ws;
}
Vehicle::Dynamics Vehicle::Vehicle_dp::dynamics()
{
	Vehicle::Dynamics sample;
	sample.Speed(45);
	sample.Wheel_Speed(wheels());
	sample.Acceleration(10);
	sample.Steering_Angle(12);
	return sample;
}
void Vehicle::Vehicle_dp::logic()
{
    Vehicle::VehicleData_t sample;
	while (!stop_requested) {
		sample.ID(0x1234);
		sample.Engine(engine());
		sample.Dynamics(dynamics());
		w_vehicle.write(sample);
		waitset.dispatch(dds::core::Duration(2));
	}
}
