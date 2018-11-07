/*
Kyle Cheung
networkinterfacelist.h
October 4, 2018
*/
#ifndef NETWORKINTERFACELIST_H
#define NETWORKINTERFACELIST_H

#include "networkinterface.h"
#include <iostream>
#include <string>
#include <dirent.h>
#include <vector>
#include <fstream>

class networkinterfacelist_class
{
public:
  networkinterfacelist_class();
  std::vector<networkinterface_class> create_device();
  void to_string();

private:
  struct dirent *ent;
  DIR *dir;
  std::vector<std::string> dir_list;
  std::vector<networkinterface_class> list;
  std::ifstream inFile;
  std::string device;
  std::string macaddress;
  std::string line;
};

#endif
