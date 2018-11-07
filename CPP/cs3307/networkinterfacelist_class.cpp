/*
Kyle Cheung
networkinterfacelist_class.cpp
October 4, 2018
*/
#include "networkinterfacelist.h"
/*
get list of network interfaces and push them into a vector list
default constructor
*/
networkinterfacelist_class::networkinterfacelist_class(){
  if ((dir = opendir ("/sys/class/net")) != NULL){
    while ((ent = readdir (dir)) != NULL) {
      std::string device(ent->d_name);

      //skips the parent and current folder
      if(device == "." || device == ".."){
        continue;
      }

      dir_list.push_back(device);
    }
    closedir (dir);
  }
}

/*
iterate through the devices and find their mac addresses
create_device();
returns a vector dir_list
*/
std::vector<networkinterface_class> networkinterfacelist_class::create_device(){
  for( std::vector<std::string>::iterator it = dir_list.begin(); it != dir_list.end(); ++it){
    if ((dir = opendir ( ("/sys/class/net/" + *it).c_str() )) != NULL){

      //opens the address file saves mac address in line
      inFile.open("/sys/class/net/" + *it + "/address");
      while (getline(inFile, line)) {
        macaddress = line.c_str();
      }

      //creates a new networkinterface class and pushes it onto a list
      networkinterface_class obj( *it , macaddress);
      list.push_back(obj);
      inFile.close();
    }
  }
  return list;
}
/*
iterates over the list of network devices and prints their name and mac address
formats the output
*/
void networkinterfacelist_class::to_string(){
  for(std::vector<networkinterface_class>::iterator it = list.begin(); it != list.end(); ++it){
    (*it).to_string();
  }
}
