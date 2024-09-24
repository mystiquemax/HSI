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


#ifndef DISCOVERY_TIMING_TESTS_DP
#define DISCOVERY_TIMING_TESTS_DP
#include <atomic>
#include <set>
#include <mutex>
#include <chrono>
#include <thread>
#include <dds/core/cond/WaitSet.hpp>
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include "HSI_Standard_topics.hpp"

// Anonymous namespace
namespace
{
	class CustomDataReaderListener : public dds::sub::NoOpDataReaderListener<DeviceInformation::DeviceElement_t> {
	public:
		CustomDataReaderListener(const int num_datawriters) : num_datawriters(num_datawriters)
		{

		}
		// Override the on_subscription_matched method
		void on_subscription_matched(
			dds::sub::DataReader<DeviceInformation::DeviceElement_t>& reader,
			const dds::core::status::SubscriptionMatchedStatus& status) override
		{
			if (status.current_count() >= num_datawriters && !is_matched)
			{
				timestamp_match = std::chrono::high_resolution_clock::now();
				is_matched = true;
			}
		}

		bool is_reader_matched() const { return is_matched; }

		std::chrono::time_point<std::chrono::high_resolution_clock> timestamp_match;

	private:
		const int num_datawriters;
		bool is_matched = false;
	};

	class CustomDataWriterListener : public dds::pub::NoOpDataWriterListener<DeviceInformation::DeviceElement_t> {
	public:
		CustomDataWriterListener(const int num_datareaders) : num_datareaders(num_datareaders)
		{
		}

		// Override the on_subscription_matched method
		void on_publication_matched(dds::pub::DataWriter<DeviceInformation::DeviceElement_t>& reader,
			const dds::core::status::PublicationMatchedStatus& status) override
		{
			if (status.current_count() >= num_datareaders && !is_matched)
			{
				timestamp_match = std::chrono::high_resolution_clock::now();
				is_matched = true;
			}
		}

		bool is_writer_matched() const { return is_matched; }

		std::chrono::time_point<std::chrono::high_resolution_clock> timestamp_match;

	private:
		const int num_datareaders;
		bool is_matched = false;
	};
};

class Timing_Tests_dp
{
public:
    Timing_Tests_dp(const int num_reader_endpoints, const int num_writer_endpoints, const int num_running_applications, const std::string& dp_name);
	std::vector<long> get_readers_microseconds_matching_times() const;
	std::vector<long> get_writers_microseconds_matching_times() const;

	void start_test();
	void stop_test();
	bool is_finished();
private:
	dds::domain::DomainParticipant dp = dds::core::null;

	std::chrono::time_point<std::chrono::high_resolution_clock> init_time;

    std::vector<dds::sub::DataReader<DeviceInformation::DeviceElement_t>> readers;
    std::vector<dds::pub::DataWriter<DeviceInformation::DeviceElement_t>> writers;

	std::vector<std::shared_ptr<CustomDataReaderListener>> reader_listeners;
	std::vector<std::shared_ptr<CustomDataWriterListener>> writer_listeners;

    dds::sub::Subscriber subscriber = dds::core::null;
    dds::pub::Publisher publisher = dds::core::null;

	std::atomic_int num_finished_readers = false;
	std::atomic_int num_finished_writers = false;

    dds::topic::Topic<DeviceInformation::DeviceElement_t> topic = dds::core::null;;
};
#endif
