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


#include "GNSS_dp.hpp"
#include <dds/core/QosProvider.hpp>
#include <ctime>

GNSS::GNSS_dp::GNSS_dp(const std::string& domain_participant_name)
{
    auto default_provider = dds::core::QosProvider::Default();
    dp = default_provider.extensions().create_participant_from_config(domain_participant_name);
    w_gnss = rti::pub::find_datawriter_by_name<dds::pub::DataWriter<GNSS::PositionData_t>>(dp, "p_gnss::w_gnss");
    if (w_gnss == dds::core::null)
    {
        throw std::runtime_error("Looking up w_pd_values failed. Are all necessary DDS-XML files loaded?");
    }
}
void GNSS::GNSS_dp::start_logic()
{
    // lat 
    // lon
    // radius in km
    // increments the angle with 0.1 radians
    logic_thread = std::thread(&GNSS::GNSS_dp::logic, this, 48.402578, 11.692824, 5, 0.1);
}
void GNSS::GNSS_dp::stop_logic()
{
    stop_requested = true;
    std::cout << "Application shutdown initiated..." << std::endl;
    logic_thread.join();
}
bool GNSS::GNSS_dp::logic_running()
{
    return logic_thread.joinable();
}
/*
  Function to set the date
*/
Common::Date GNSS::GNSS_dp::date() {
    std::time_t currTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currTime);
    Common::Date date;
    date.Day(localTime->tm_mday);
    date.Month(localTime->tm_mon + 1);
    date.Year(localTime->tm_year + 1900);
    return date;
}
/*
  Function to set the time
*/
Common::Time GNSS::GNSS_dp::time() {
    std::time_t currTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currTime);
    Common::Time time;
    time.Hours_24(localTime->tm_hour);
    time.Minutes(localTime->tm_min);
    time.Seconds(localTime->tm_sec);
    return time;
}
/*
  Function to set the reference stations
*/
::dds::core::optional< rti::core::bounded_sequence<GNSS::ReferenceStation, 10L>> GNSS::GNSS_dp::reference_stations() {
    std::vector<GNSS::ReferenceStation> reference_stations;
    reference_stations.push_back(GNSS::ReferenceStation(1234, 1337, 1));
    /* Maybe add more reference stations? */
    rti::core::bounded_sequence<GNSS::ReferenceStation, 10L> boundedSequence(reference_stations.begin(), reference_stations.end());
    ::dds::core::optional< rti::core::bounded_sequence<GNSS::ReferenceStation, 10L>> optionalValue(boundedSequence);
    return optionalValue;
}
void GNSS::GNSS_dp::logic(double center_lat, double center_lon, double radius, float step)
{
    GNSS::PositionData_t sample;
    double angle = 0.0;
    while (!stop_requested) {
        std::time_t currTime = std::time(nullptr);
        std::tm* localTime = std::localtime(&currTime);
        sample.NAME(0x4750474741); // GPGGA in hex
        sample.SID(456);
        sample.PositionDate(date());
        sample.PositionTime(time());
        sample.NumOfSVs(4);
        sample.Method(1);
        sample.HDOP(1);
        /*
           Geoidal Separation calculated by https://www.unavco.org/software/geodetic-utilities/geoid-height-calculator/geoid-height-calculator.html
           Geoidal Separation = Geoid Height - Ellps Height
        */
        sample.GeoidalSeparation(-34.057176);
        sample.Alt(471.5);
        double dx = radius * cos(angle); // in km
        double dy = radius * sin(angle); // in km
        // 1 latitude degree is approx. 110.574 km
        double new_lat = center_lat + (dx / 110.574);
        // 1 longitude degree is approx. 111.32 km
        double new_lon = center_lon + (dy / (111.32 * cos(center_lat * PI / 180)));
        sample.Lat(new_lat);
        sample.Lon(new_lon);
        w_gnss.write(sample);
        angle += step;
        waitset.dispatch(dds::core::Duration(2)); // wait for 2 second before sending the next sample
    }
}
