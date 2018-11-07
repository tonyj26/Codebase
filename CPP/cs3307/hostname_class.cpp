/*
Kyle Cheung
hostname_class.cpp
October 4, 2018
*/
#include "hostname.h"

/*
default constructor
hostname_class()
*/
hostname_class::hostname_class()
{
  uname(&unameData);
}

/*
getter method for name
returns a string
*/

std::string hostname_class::name(){
  return unameData.sysname;
}

/*
format the output
to_string
*/
void hostname_class::to_string(){
  std::cout << "Hostname: " << hostname_class::name() << std::endl;
}
