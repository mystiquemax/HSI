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


#ifndef DOMAIN_PARTICIPANT_UTILS_HPP
#define DOMAIN_PARTICIPANT_UTILS_HPP
#include "HSI_Standard_topics.hpp"
namespace dp_utils
{
    // custom comparator for device elements
    struct device_element_ref_cmp
    {
        bool operator()(const DeviceInformation::DeviceElement_t &a, const DeviceInformation::DeviceElement_t &b) const
        {
            if (a.element_ref().name() != b.element_ref().name())
            {
                return a.element_ref().name() < b.element_ref().name();
            }
            else
            {
                return a.element_ref().element_id() < b.element_ref().element_id();
            }
        };
    };
    // custom comparator for device elements
    struct element_ref_cmp
    {
        bool operator()(const DeviceInformation::ElementReference_t &a, const DeviceInformation::ElementReference_t &b) const
        {
            if (a.name() != b.name())
            {
                return a.name() < b.name();
            }
            else
            {
                return a.element_id() < b.element_id();
            }
        };
    };  
}
  
#endif
