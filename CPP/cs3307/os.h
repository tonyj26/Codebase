/*
Kyle Cheung
os.h
October 4, 2018
*/
#ifndef OS_H
#define OS_H

#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <iostream>
#include <string.h>

class os_class
{
public:
  os_class();
  std::string sysname();
  std::string release();
  std::string version();
  std::string machine();
  std::string f_uptime();
  long uptime();
  void to_string();

private:
  struct utsname unameData;
  struct sysinfo info;
  std::string str;
  long days;
  long total;
  long hour;
  long minute;
  long sec;

};

#endif
