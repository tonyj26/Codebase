/*
Kyle Cheung
main_util.cpp
October 4, 2018
*/

#include "hostname.h"
#include "os.h"
#include "processorinfo.h"
#include "networkinterface.h"
#include "networkinterfacelist.h"
#include "process.h"
#include "processlist.h"
#include "meminfo.h"

int main(){
  while(true){
    int i;
    std::cout << "Please Choose Util" << std::endl;
    std::cout << "Press 1 for hostname" << std::endl;
    std::cout << "Press 2 for operating system" << std::endl;
    std::cout << "Press 3 for Processor Information" << std::endl;
    std::cout << "Press 4 for Memory" << std::endl;
    std::cout << "Press 5 for Network Interfaces" << std::endl;
    std::cout << "Press 6 for Processes" << std::endl;
    std::cout << "Press 7 for Everything" << std::endl;
    std::cout << "Press 0 to Exit" << std::endl;
    std::cout << "Please Enter a number: ";
    std::cin >> i;

    switch(i) {
      case 1 : {
        std::cout << "\n";
        hostname_class obj;
        obj.to_string();
        std::cout << "\n\n";
      };
      break;
      case 2 : {
        std::cout << "\n";
        os_class obj;
        obj.to_string();
        std::cout << "\n\n";
      };
      break;
      case 3 : {
        std::cout << "\n";
        processorinfo_class obj;
        obj.to_string();
        std::cout << "\n\n";
      };
      break;
      case 4 : {
        std::cout << "\n";
        meminfo_class obj;
        obj.to_string();
        std::cout << "\n\n";
      };
      break;
      case 5 : {
        std::cout << "\n";
        networkinterfacelist_class obj;
        obj.create_device();
        obj.to_string();
        std::cout << "\n\n";
      };
      break;
      case 6 : {
        std::cout << "\n";
        processlist_class obj;
        obj.populate();
        obj.to_string();
        std::cout << "\n\n";
      };
      break;
      case 7 : {
        std::cout << "\n";
        hostname_class host;
        os_class os;
        processorinfo_class processorinfo;
        meminfo_class meminfo;
        networkinterfacelist_class network;
        network.create_device();
        processlist_class processlist;
        processlist.populate();

        host.to_string();
        std::cout << "\n";
        os.to_string();
        std::cout << "\n";
        processorinfo.to_string();
        std::cout << "\n";
        meminfo.to_string();
        std::cout << "\n";
        network.to_string();
        std::cout << "\n";
        processlist.to_string();
        std::cout << "\n\n";
      };
      break;
      case 0 : return 0;
      break;
      default: std::cout << "invalid input";
      break;
    }
  }
  return 0;
}
