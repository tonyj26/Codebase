/*
Kyle Cheung
process.h
October 4, 2018
*/
#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <iostream>

class process_class
{
public:
  process_class();
  process_class(std::string, std::string, std::string, std::string, std::string);
  std::string get_id();
  std::string get_name();
  std::string get_owner_uid();
  std::string get_parent_id();
  std::string get_state();
  void to_string();

private:
  std::string id;
  std::string name;
  std::string owner_uid;
  std::string parent_id;
  std::string state;

};

#endif
