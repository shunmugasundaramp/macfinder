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
  * @file MACFinder.cpp
  * @brief Implementation of MACFinder which is providing a MACADDRESS of the given IP
  * @author Shunmuga (ssundaramp@outlook.com)
  *
  */

// System headers
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if_arp.h>
#include <arpa/inet.h>
#include <string>

// User headers
#include "MACFinder.hpp"

using namespace std;

namespace AKKU {

namespace MACFinder {

static bool _Ping( const std::string& address )
{
    // Format a command string
    std::string command = "ping -c 2 " + address + " 2>&1";

    // Run Popen
    FILE *in;
    char buff[512];

    // Test output
    if(!(in = popen(command.c_str(), "r"))){
        return false;
    }

    // Parse output
    while(fgets(buff, sizeof(buff), in)!=NULL);

    return (pclose(in) == 0);
}

bool Get(const char* host_interface, const char* remote_ip, string& macaddress)
{
    int s;
    struct arpreq areq;
    struct sockaddr_in *sin;
    struct in_addr ipaddr;
    struct sockaddr_in sa;
    char buff[256];

    if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == -1 ||
        0 == inet_pton(AF_INET, remote_ip, &(sa.sin_addr)) ||
        0 == inet_aton(remote_ip, &ipaddr) ||
        !_Ping(remote_ip)) {
        return false;
    }

    /* Make the ARP request. */
    memset(&areq, 0, sizeof(areq));
    sin = (struct sockaddr_in *) &areq.arp_pa;
    sin->sin_family = AF_INET;

    sin->sin_addr = ipaddr;
    sin = (struct sockaddr_in *) &areq.arp_ha;
    sin->sin_family = ARPHRD_ETHER;

    strncpy(areq.arp_dev, host_interface, 15);

    if (ioctl(s, SIOCGARP, (caddr_t) &areq) == -1) {
        return false;
    }

    unsigned char *ptr = (unsigned char *)(&areq.arp_ha)->sa_data;
    sprintf(buff, "%02X:%02X:%02X:%02X:%02X:%02X",
            (ptr[0] & 0xff), (ptr[1] & 0xff), (ptr[2] & 0xff),
            (ptr[3] & 0xff), (ptr[4] & 0xff), (ptr[5] & 0xff));

    macaddress = buff;
    return true;
}

}; // namespace MACFinder

}; // namespace AKKU
