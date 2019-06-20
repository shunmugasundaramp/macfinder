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
  * @file usage.cpp
  * @brief test code
  * @author Shunmuga (ssundaramp@outlook.com)
  *
  */

#include <stdio.h>
#include <string>
#include <iostream>

#include "MACFinder.hpp"

using namespace std;

int main(int argc, char** argv)
{
    string interface, remoteip, macaddress;
    while (true) {
        cout << "Enter the Host interface: ";
        cin >> interface;
        if (interface == "exit") {
            break;
        }
        cout << "Enter the remote ip: ";
        cin >> remoteip;
        if (AKKU::MACFinder::Get(interface.c_str(), remoteip.c_str(), macaddress)) {
            cout << "MAC Address: " << macaddress << "\n";
        } else {
            cout << "Failed to get the MAC Address for the ip {" << remoteip << "}\n";
        }
    }

    return 0;
}
