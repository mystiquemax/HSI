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
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <dds/core/QosProvider.hpp>
#include <dds/domain/ddsdomain.hpp>
#include <dds/topic/find.hpp>
#include "Latency_Tests_dp.hpp"

//
//	Latency Tester -> Pings Message, waits for rebound and messures round-trip-time
//

Latency_Tests_dp::Latency_Tests_dp(const int num_messages, const std::string& dp_name) : num_messages(num_messages)
{
	auto default_provider = dds::core::QosProvider::Default();
	dp = default_provider.extensions().create_participant_from_config(dp_name);

	// Ignore messages from ourselves on all topics
	dds::domain::ignore(dp, dp.instance_handle());
	
	this->subscriber = dds::sub::Subscriber(dp);
	this->publisher = dds::pub::Publisher(dp);

	this->topic = dds::topic::Topic<DeviceInformation::DeviceElement_t>(dp, "TimeTestTopic");

	this->reader = dds::sub::DataReader<DeviceInformation::DeviceElement_t>(subscriber, topic);
	this->writer = dds::pub::DataWriter<DeviceInformation::DeviceElement_t>(publisher, topic);

	// Just any test message
	this->test_message = DeviceInformation::DeviceElement_t("TestDevice", DeviceInformation::ElementReference_t(1,1), DeviceInformation::ElementReference_t(1,1), 0);

	waitset.attach_condition(dds::sub::cond::ReadCondition(
		reader,
		dds::sub::status::DataState::any(),
		std::bind(&Latency_Tests_dp::r_message_read_callback, this))
	);

	// Run logic thread 
	this->logic_thread = std::thread([&] {
		while (!stop_requested)
		{
			waitset.dispatch(dds::core::Duration(0, 100));
		}
	});
}

void Latency_Tests_dp::stop_logic()
{
	stop_requested = true;
	logic_thread.join();
}

bool Latency_Tests_dp::is_done() const
{
	return this->is_test_done;
}

const std::vector<long>& Latency_Tests_dp::get_latency_times() const
{
	return this->latency_times;
}

void Latency_Tests_dp::conduct_latency_test()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	for (unsigned i = 0; i < num_messages; i++)
	{
		// Make sure no other message is sent while the old one isn't received yet
		sending_time = std::chrono::high_resolution_clock::now();
		writer.write(test_message);

		std::unique_lock<std::mutex> lock(message_mutex);
		if (send_next_message.wait_for(lock, std::chrono::seconds(10)) == std::cv_status::timeout)
		{
			// Message timed out
			std::cout<<("Message timed out! Check connection.")<<std::endl;
			is_test_done = true;
			return;
		}
		std::cout << "Message " << i << " returned successfully" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	is_test_done = true;
}

void Latency_Tests_dp::r_message_read_callback()
{

	for (auto msg : reader.take())
	{
		if (msg.info().valid())
		{
			auto current_time = std::chrono::high_resolution_clock::now();

			// One round-trip time
			latency_times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(current_time - sending_time).count());
			send_next_message.notify_one();
		}
	}
}

//
//	Reflector -> Receives Message and puts it back on the topic
//

Latency_Tests_Reflector_dp::Latency_Tests_Reflector_dp(const std::string& dp_name)
{
	auto default_provider = dds::core::QosProvider::Default();
	dp = default_provider.extensions().create_participant_from_config(dp_name);

	// Ignore messages from ourselves on all topics
	dds::domain::ignore(dp, dp.instance_handle());

	this->subscriber = dds::sub::Subscriber(dp);
	this->publisher = dds::pub::Publisher(dp);

	this->topic = dds::topic::Topic<DeviceInformation::DeviceElement_t>(dp, "TimeTestTopic");

	this->reader = dds::sub::DataReader<DeviceInformation::DeviceElement_t>(subscriber, topic);
	this->writer = dds::pub::DataWriter<DeviceInformation::DeviceElement_t>(publisher, topic);

	waitset.attach_condition(dds::sub::cond::ReadCondition(
		reader,
		dds::sub::status::DataState::any(),
		std::bind(&Latency_Tests_Reflector_dp::r_message_read_callback, this))
	);

	// Run logic thread 
	this->logic_thread = std::thread([&] {
		while (!stop_requested)
		{
			waitset.dispatch(dds::core::Duration(1));
		}
	});
}

void Latency_Tests_Reflector_dp::stop_logic()
{
	stop_requested = true;
	logic_thread.join();
}

void Latency_Tests_Reflector_dp::r_message_read_callback()
{
	for (auto msg : reader.take())
	{
		if (msg.info().valid())
		{
			// Reflect Message
			writer.write(msg.data());
		}
	}
}