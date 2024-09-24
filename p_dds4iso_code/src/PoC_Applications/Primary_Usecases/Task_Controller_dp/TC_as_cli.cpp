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


#include "TC_as_cli.hpp"
#include "TC_logic.hpp"
#include <iostream>
void dummy_update_tank_cb(float min_fill, float curr_fill, float max_fill)
{
    std::cout << "min_fill: " << min_fill << std::endl;
    std::cout << "curr_fill: " << curr_fill << std::endl;
    std::cout << "max_fill: " << max_fill << std::endl;
}
void dummy_update_Device_t_cb(const char* id, const char* designator, const char* softwareversion,
    const char* friendly_name, const char* serialnumber, const char* structurelabel,
    const char* localizationlabel)
{
    std::cout << "id: " << id << std::endl;
    std::cout << "designator: " << designator << std::endl;
    std::cout << "softwareversion: " << softwareversion << std::endl;
    std::cout << "friendly_name: " << friendly_name << std::endl;
    std::cout << "serialnumber: " << serialnumber << std::endl;
    std::cout << "structurelabel: " << structurelabel << std::endl;
    std::cout << "localizationlabel: " << localizationlabel << std::endl;
}
void dummy_update_DeviceElement_t_cb(const char* name, uint64_t element_ref_name, uint64_t element_ref_element_num,
    uint64_t parent_ref_name, uint64_t parent_ref__element_num)
{
    std::cout << "name: " << name << std::endl;
    std::cout << "element_ref_name: " << element_ref_name << std::endl;
    std::cout << "element_ref_element_num: " << element_ref_element_num << std::endl;
    std::cout << "parent_ref_name: " << parent_ref_name << std::endl;
    std::cout << "parent_ref__element_num: " << parent_ref__element_num << std::endl;
}
void dummy_update_ControlHandlingCapabilities_t_cb(uint64_t element_ref_name, uint64_t element_ref_element_num,
    const char* handling_group, uint8_t option_nr, const char* unit)
{
    std::cout << "element_ref_name: " << element_ref_name << std::endl;
    std::cout << "element_ref_element_num: " << element_ref_element_num << std::endl;
    std::cout << "handling_group: " << handling_group << std::endl;
    std::cout << "option_nr: " << static_cast<int>(option_nr) << std::endl;
    std::cout << "unit: " << unit << std::endl;
}
void dummy_update_ControlHandlingValues_t_cb(uint64_t element_ref_name, uint64_t element_ref_element_num,
    const char* handling_feature, const char* handling_group, double value, const char* unit)
{
    /*std::cout << "element_ref_name: " << element_ref_name << std::endl;
    std::cout << "element_ref_element_num: " << element_ref_element_num << std::endl;
    std::cout << "handling_feature: " << handling_feature << std::endl;
    std::cout << "handling_group: " << handling_group << std::endl;
    std::cout << "value: " << value << std::endl;
    std::cout << "unit: " << unit << std::endl;*/
}
double dummy_get_setpoint()
{
    return 101.2;
}
void dummy_read_lat_lon_cb(uint64_t name, double lat, double lon)
{
    std::cout << "NAME: " << name << std::endl;
    std::cout << "lat: " << lat << std::endl;
    std::cout << "lon: " << lon << std::endl;
}
void dummy_name_disconnect(uint64_t name)
{
    std::cout << "NAME: " << name << " is disconnected\n\n\n\n" << std::endl;
}
void main()
{
    const bool isCalledFromGuiNotCmd = false;
    TC_logic_run(isCalledFromGuiNotCmd,dummy_update_tank_cb, dummy_update_Device_t_cb, dummy_update_DeviceElement_t_cb,
        dummy_update_ControlHandlingCapabilities_t_cb, dummy_update_ControlHandlingValues_t_cb,
        dummy_get_setpoint, dummy_read_lat_lon_cb, dummy_name_disconnect);
}
