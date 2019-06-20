/*
Copyright [2016] [ssundaramp@outlook.com]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/**
  *
  * @file MACFinder.hpp
  * @brief Implementation of MACFinder which is providing a MACADDRESS of the given IP
  * @author Shunmuga (ssundaramp@outlook.com)
  *
  */

#ifndef _MACFinder_hpp_
#define _MACFinder_hpp_

// System headers

// User headers

#pragma once

using namespace std;

namespace AKKU {

namespace MACFinder {

    bool Get(const char* host_interface, const char* remote_ip, string& macaddress);

}; // namespace MACFinder

}; // namespace AKKU

#endif //_MACFinder_hpp_

