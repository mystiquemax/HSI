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


#ifndef APPLICATION_UTILS_HPP
#define APPLICATION_UTILS_HPP
#include <string>
#include <csignal>
#include "HSI_Standard_topics.hpp"
namespace application
{
	volatile std::atomic_bool run_application = true;
	void application_stop_handler(int)
	{
		run_application = false;
		// signals have to be re-registered 
		std::signal(SIGINT, application_stop_handler);
		std::signal(SIGTERM, application_stop_handler);
	}
    inline void setup_signal_handlers()
    {
        std::signal(SIGINT, application_stop_handler);
        std::signal(SIGTERM, application_stop_handler);
    }
    DeviceInformation::DeviceElement_t parse_device_info(int argc, char *argv[])
    {
        DeviceInformation::DeviceElement_t device_info;
        for (int i = 1; i < argc; i++)
        {
            std::string param = argv[i];
            if (param == "-display_name")
            {
                device_info.name(argv[++i]);
            }
            else if (param == "-this_ref")
            {
                std::string addr_str = argv[++i];
                auto sep_idx = addr_str.find('.');
                device_info.element_ref().name(std::stoi(addr_str.substr(0, sep_idx)));
                device_info.element_ref().element_id(std::stoi(addr_str.substr(sep_idx + 1)));
            }
            else if (param == "-parent_ref")
            {
                std::string addr_str = argv[++i];
                auto sep_idx = addr_str.find('.');
                device_info.parent_ref().name(std::stoi(addr_str.substr(0, sep_idx)));
                device_info.parent_ref().element_id(std::stoi(addr_str.substr(sep_idx + 1)));
            }
            else
            {
                std::cout << "Unknown parameter: " << param << std::endl;
            }
        }
        return device_info;
    } 
} // namespace application
#endif
