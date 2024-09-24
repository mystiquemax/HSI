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


#pragma once
#include <cstdint>
#include "HSI_Standard_topics.hpp"
#include "HSI_Standard_topicsPlugin.hpp"
#ifdef __cplusplus
extern "C" {
#endif
	void TC_logic_stop();
	// TC_logic_run takes function pointers as arguments. these callbacks are implemented in the C# GUI
  void TC_logic_run(
      bool isCalledFromGuiNotCmd,
      void (*update_tank_cb)(float min_fill, float curr_fill, float max_fill),
      void (*update_Device_t_cb)(const char* id, const char* designator, const char* softwareversion,
          const char* friendly_name, const char* serialnumber, const char* structurelabel,
          const char* localizationlabel),
      void (*update_DeviceElement_t_cb)(const char* name, uint64_t element_ref_name, uint64_t element_ref_element_num,
          uint64_t parent_ref_name, uint64_t parent_ref__element_num),
      void (*update_ControlHandlingCapabilities_t_cb)(uint64_t element_ref_name, uint64_t element_ref_element_num,
          const char* handling_group, uint8_t option_nr, const char* unit),
      void (*update_ControlHandlingValues_t_cb)(uint64_t element_ref_name, uint64_t element_ref_element_num,
          const char* handling_feature, const char* handling_group, double value, const char* unit),
      double (*get_setpoint)(),
      void (*read_lat_lon_cb)(uint64_t name, double lat, double lon),
      void (*name_disconnect)(uint64_t name)
  );
	//double test_readUpdate_app_rate();
	static int TC_init(bool isCalledFromGuiNotCmd);
#ifdef __cplusplus
}
#endif
