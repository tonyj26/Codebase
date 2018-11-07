/*
Kyle Cheung
meminfo.h
October 4, 2018
*/
#ifndef MEMINFO_H
#define MEMINFO_H

#include <sys/sysinfo.h>
#include <string>
#include <iostream>

class meminfo_class {
public:
  meminfo_class();
  unsigned long total_mem();
  unsigned long free_mem();
  void to_string();

private:
  struct sysinfo info;
  unsigned long mtotal_mem;
  unsigned long mfree_mem;
};

#endif
