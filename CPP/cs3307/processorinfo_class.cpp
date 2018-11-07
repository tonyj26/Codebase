/*
Kyle Cheung
processorinfo_class.cpp
October 4, 2018
*/
#include "processorinfo.h"

/*
default constructor
*/
processorinfo_class::processorinfo_class()
{
  sysinfo(&info);
  inFile.open("/proc/cpuinfo");

  if (!inFile){
    std::cerr << "Unable to open cpuinfo";
    exit(1);
  }

  //matches strings with desired information and puts it into variables
  if(inFile.is_open()){
    while(getline(inFile, line)){
      if(line.find("vendor_id", 0) == 0 ){
        mvendor = line.c_str();
      }
      if(line.find("model name", 0) == 0 ){
        mmodel = line.c_str();
      }
      if(line.find("cpu MHz", 0) == 0){
        mclockspeed = line.c_str();
      }
    }
    inFile.close();
  }
}

/*
getter method for vendor
vendor();
returns a string
*/
std::string processorinfo_class::vendor(){
  return mvendor;
}

/*
getter method for model
model();
returns a string
*/
std::string processorinfo_class::model(){
  return mmodel;
}

/*
getter method for clockspeed
clockspeed();
returns a string
*/
std::string processorinfo_class::clockspeed(){
  return mclockspeed;
}

/*
getter method for load
systemload();
returns an unsigned long
*/
unsigned long processorinfo_class::systemload(int loadtime){
  return info.loads[loadtime];
}

/*
formatts the output
*/
void processorinfo_class::to_string(){
  std::cout << processorinfo_class::vendor() << std::endl;
  std::cout << processorinfo_class::model() << std::endl;
  std::cout << processorinfo_class::clockspeed() << std::endl;
  std::cout << "Load at 1 min \t: " << processorinfo_class::systemload(0) << std::endl;
  std::cout << "Load at 5 min\t: " << processorinfo_class::systemload(1) << std::endl;
  std::cout << "Load at 15 min \t: " << processorinfo_class::systemload(2) << std::endl;
}
