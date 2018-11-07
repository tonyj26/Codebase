/*
Kyle Cheung
network_main.cpp
October 4, 2018
*/
#include "networkinterfacelist.h"
#include "networkinterface.h"

int main(){
  networkinterfacelist_class networkinterfacelist;
  networkinterfacelist.create_device();
  networkinterfacelist.to_string();
  return 0;
}
