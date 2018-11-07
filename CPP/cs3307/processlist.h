/*
Kyle Cheung
processlist.h
October 4, 2018
*/
#ifndef PROCESSLIST_H
#define PROCESSLIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "process.h"
#include <ctype.h>
#include <dirent.h>

class processlist_class
{
public:
  processlist_class();
  std::vector<process_class> populate();
  void to_string();

private:
  struct dirent *ent;
  DIR *dir;
  std::vector<std::string> dir_list;
  std::vector<process_class> list;
  std::ifstream inFile;
  std::string line;
  std::string process;
  std::string state;
  std::string pid;
  std::string ppid;
  std::string uid;

};

#endif
