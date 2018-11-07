/*
Kyle Cheung
processorinfo.h
October 4, 2018
*/
#ifndef PROCESSORINFO_H
#define PROCESSORINFO_H

#include <sys/sysinfo.h>
#include <iostream>
#include <string>
#include <fstream>
#include <dirent.h>

class processorinfo_class {
public:
  processorinfo_class();
  std::string vendor();
  std::string model();
  std::string clockspeed();
  unsigned long systemload(int);
  void to_string();

private:
  struct sysinfo info;
  unsigned long loads[3];
  std::ifstream inFile;
  std::string line;
  std::string mvendor;
  std::string mmodel;
  std::string mclockspeed;
};

#endif
