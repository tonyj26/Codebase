/*
Kyle Cheung
os_class.cpp
October 4, 2018
*/
#include "os.h"

/*
default constructor
*/
os_class::os_class(){
  uname(&unameData);
  sysinfo(&info);
}

/*
getter method for sysname
sysname();
returns a string
*/
std::string os_class::sysname(){
  return unameData.sysname;
}

/*
getter method for release
release();
returns a string
*/
std::string os_class::release(){
  return unameData.release;
}

/*
getter method for version
version();
returns a string
*/
std::string os_class::version(){
  return unameData.version;
}

/*
getter method for machine
machine();
returns a string
*/
std::string os_class::machine(){
  return unameData.machine;
}

/*
getter methof for uptime
uptime();
returns a long
*/
long os_class::uptime(){
  return info.uptime;
}

/*
formats the time into days:hours:minutes:seconds
sysname();
returns a string
*/
std::string os_class::f_uptime(){
  total = info.uptime;
  days = total / 86400;
  hour = total / 3600;
  minute = (total % 3600) / 60;
  sec = total % 60;
  str = std::to_string(days) + ":" + std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(sec);

  return str;
}

/*
format the output
*/
void os_class::to_string(){
  std::cout << "Sysname: " << os_class::sysname() << std::endl;
  std::cout << "Release: " << os_class::release() << std::endl;
  std::cout << "Version: " << os_class::version() << std::endl;
  std::cout << "Machine: " << os_class::machine() << std::endl;
  std::cout << "Uptime: " << os_class::f_uptime() << std::endl;
}
