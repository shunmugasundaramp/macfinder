
                   AKKU::MACFinder, Release 2.0.0

This is AKKU::MACFinder, a C++ library to retrieve the MACAddress of
remote IP written by Shunmuga Sundaram using ARP.  It is a independent 
source which should not having any other thirdparty software references

Currently it is having a support to compile with GCC Compiler.
Hopefully it will come for other compilers too.

AKKU MACFinder is free software.  You may copy, distribute, and modify
it under the terms of the License contained in the file COPYING
distributed with this package.  This license is the same as the
Apache Consortium license.


# AKKU::MACFinder
Light weight module to find the MAC Address of any remote ip

1. Easy to include anywhere
2. No dependencies

# Usage
## In Linux

### To Compile

./linbuild.sh

### To Run

./objs/usage.exe

## In Windows
### To Compile

winbuild.bat

### To Run

objs\usage.exe

# Output
```
Enter the Host interface: em1
Enter the remote ip: 192.168.1.9
MAC Address: 14:18:77:D1:D6:19
```