/*
Kyle Cheung
networkinterface.h
October 4, 2018
*/
#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H

#include <iostream>
#include <string>

class networkinterface_class
{
public:
  networkinterface_class();
  networkinterface_class(std::string, std::string);
  std::string get_name();
  std::string get_mac();
  void to_string();

private:
  std::string name;
  std::string mac;

};

#endif
