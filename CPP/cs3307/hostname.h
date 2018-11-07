/*
Kyle Cheung
hostname.h
October 4, 2018
*/
#ifndef HOSTNAME_H
#define HOSTNAME_H

#include <sys/utsname.h>
#include <iostream>

class hostname_class
{
public:
  hostname_class();
  std::string name();
  void to_string();

private:
  struct utsname unameData;
};

#endif
