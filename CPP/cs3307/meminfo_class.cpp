/*
Kyle Cheung
meminfo_class.cpp
October 4, 2018
*/
#include "meminfo.h"

/*
default constructor
*/
meminfo_class::meminfo_class(){
  sysinfo(&info);
}

/*
getter method for total Memory
total_mem();
returns an unsigned long
*/
unsigned long meminfo_class::total_mem(){
  return info.totalhigh;
}

/*
getter method for free Memory
free_mem();
returns an unsigned long
*/
unsigned long meminfo_class::free_mem(){
  return info.freehigh;
}

/*
format the output
to_string();
*/
void meminfo_class::to_string(){
  std::cout << "Total Memory \t: " << meminfo_class::total_mem() << std::endl;
  std::cout << "Free Memory \t: " << meminfo_class::free_mem() << std::endl;
}
