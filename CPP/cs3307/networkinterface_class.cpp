/*
Kyle Cheung
networkinterface_class.cpp
October 4, 2018
*/
#include "networkinterface.h"

/*
default constructor
*/
networkinterface_class::networkinterface_class(){
  name = "N/A";
  mac = "N/A";
}

/*
regular constructor
*/
networkinterface_class::networkinterface_class(std::string device, std::string macaddress){
  name = device;
  mac = macaddress;
}

/*
getter method for Name
get_name();
returns a string
*/
std::string networkinterface_class::get_name(){
  return name;
}

/*
getter method for mac
get_mac();
returns a string
*/
std::string networkinterface_class::get_mac(){
  return mac;
}

/*
format the output
to_string();
*/
void networkinterface_class::to_string(){
  std::cout << "Name: " << networkinterface_class::get_name() << "\tMAC: " << networkinterface_class::get_mac() << std::endl;
}
