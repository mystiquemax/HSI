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


#ifndef LATENCY_TESTS_DP_HPP
#define LATENCY_TESTS_DP_HPP
#include <atomic>
#include <set>
#include <condition_variable>
#include <chrono>
#include <thread>
#include <dds/core/cond/WaitSet.hpp>
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include "HSI_Standard_topics.hpp"


// Sends messages to reflector
class Latency_Tests_dp
{
public:
	Latency_Tests_dp(const int num_messages, const std::string& dp_name);
	void conduct_latency_test();
	const std::vector<long>& get_latency_times() const;
	bool Latency_Tests_dp::is_done() const;
	void stop_logic();
private:
	void r_message_read_callback();
	dds::domain::DomainParticipant dp = dds::core::null;
	dds::sub::DataReader<DeviceInformation::DeviceElement_t> reader = dds::core::null;
	dds::pub::DataWriter<DeviceInformation::DeviceElement_t> writer = dds::core::null;

	dds::sub::Subscriber subscriber = dds::core::null;
	dds::pub::Publisher publisher = dds::core::null;

	dds::topic::Topic<DeviceInformation::DeviceElement_t> topic = dds::core::null;;

	std::chrono::time_point<std::chrono::high_resolution_clock> sending_time;
	std::vector<long> latency_times;

	std::atomic_bool is_test_done = false;
	std::atomic_bool stop_requested = false;

	std::condition_variable send_next_message;
	std::mutex message_mutex;

	DeviceInformation::DeviceElement_t test_message;
	dds::core::cond::WaitSet waitset;

	std::thread logic_thread;

	const int num_messages;
};

// Does nothing with the message but reflects it back
class Latency_Tests_Reflector_dp
{
public:
	Latency_Tests_Reflector_dp(const std::string& dp_name);
	void stop_logic();

private:
	void r_message_read_callback();

	dds::domain::DomainParticipant dp = dds::core::null;
	dds::sub::DataReader<DeviceInformation::DeviceElement_t> reader = dds::core::null;
	dds::pub::DataWriter<DeviceInformation::DeviceElement_t> writer = dds::core::null;

	dds::sub::Subscriber subscriber = dds::core::null;
	dds::pub::Publisher publisher = dds::core::null;

	dds::topic::Topic<DeviceInformation::DeviceElement_t> topic = dds::core::null;
	dds::core::cond::WaitSet waitset;

	std::atomic_bool stop_requested = false;

	std::thread logic_thread;
};
#endif
