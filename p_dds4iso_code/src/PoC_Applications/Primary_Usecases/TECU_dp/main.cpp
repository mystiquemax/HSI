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
#include "../app_utils.hpp"
#include <dds/core/QosProvider.hpp>
using namespace std::chrono_literals;
int main() {
    rti::core::QosProviderParams provider_params;
    provider_params.url_profile({ std::string(PATH_INFORMATION_MODEL) + "/HSI_Standard_topics.xml"
        , std::string(PATH_INFORMATION_MODEL) + "/HSI_generic_Tractor.xml" });
    rti::core::default_qos_provider_params(provider_params);
    rti::domain::register_type<Vehicle::VehicleData_t>("VehicleData_t");
    Vehicle::Vehicle_dp vehicle_dp;
    vehicle_dp.start_logic();
    while (application::run_application && vehicle_dp.logic_running())
    {
        // Do things, at least put thread to sleep
        std::this_thread::sleep_for(1s);
    }
    vehicle_dp.stop_logic();
}