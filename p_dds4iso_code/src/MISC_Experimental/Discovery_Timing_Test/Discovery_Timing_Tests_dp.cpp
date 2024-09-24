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
#include <chrono>
#include <dds/core/QosProvider.hpp>
#include <dds/domain/ddsdomain.hpp>
#include <dds/topic/find.hpp>
#include "Discovery_Timing_Tests_dp.hpp"


Timing_Tests_dp::Timing_Tests_dp(const int num_reader_endpoints, const int num_writer_endpoints, const int num_running_applications, const std::string& dp_name)
{
	auto default_provider = dds::core::QosProvider::Default();
	dp = default_provider.extensions().create_participant_from_config(dp_name);

	this->subscriber = dds::sub::Subscriber(dp);
	this->publisher = dds::pub::Publisher(dp);

	this->topic = dds::topic::Topic<DeviceInformation::DeviceElement_t>(dp, "TimeTestTopic");

	reader_listeners.reserve(num_reader_endpoints);
	writer_listeners.reserve(num_writer_endpoints);
	for (unsigned i = 0; i < num_reader_endpoints; i++)
	{
		readers.push_back(dds::sub::DataReader<DeviceInformation::DeviceElement_t>(subscriber, topic));
		reader_listeners.push_back(std::make_shared<CustomDataReaderListener>(num_reader_endpoints*num_running_applications));
		readers.at(i).set_listener(reader_listeners.at(i));
	}

	for (unsigned i = 0; i < num_writer_endpoints; i++)
	{
		writers.push_back(dds::pub::DataWriter<DeviceInformation::DeviceElement_t>(publisher, topic));
		writer_listeners.push_back(std::make_shared<CustomDataWriterListener>(num_writer_endpoints*num_running_applications));
		writers.at(i).set_listener(writer_listeners.at(i));
	}
}

void Timing_Tests_dp::start_test()
{
	this->init_time = std::chrono::high_resolution_clock::now();
	this->dp.enable();
}

void Timing_Tests_dp::stop_test()
{
	this->dp.close();
}

std::vector<long> Timing_Tests_dp::get_readers_microseconds_matching_times() const
{
	std::vector<long> durations;
	durations.reserve(reader_listeners.size());
	for (const auto& ts : this->reader_listeners)
	{
	    durations.push_back(std::chrono::duration_cast<std::chrono::microseconds>(ts->timestamp_match - init_time).count());
	}
	return durations;
}

std::vector<long> Timing_Tests_dp::get_writers_microseconds_matching_times() const
{
	std::vector<long> durations;
	durations.reserve(writer_listeners.size());
	for (const auto& ts : this->writer_listeners)
	{
	   durations.push_back(std::chrono::duration_cast<std::chrono::microseconds>(ts->timestamp_match - init_time).count());
	}
	return durations;
}


bool Timing_Tests_dp::is_finished()
{
	for (const auto& r_listener : reader_listeners)
	{
		if (!r_listener->is_reader_matched())
		{
			return false;
		}
	}

	for (const auto& r_writer : writer_listeners)
	{
		if (!r_writer->is_writer_matched())
		{
			return false;
		}
	}
	return true;
}