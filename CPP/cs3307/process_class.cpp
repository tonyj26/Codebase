/*
Kyle Cheung
process_class.cpp
October 4, 2018
*/
#include "process.h"

/*
default constructor
*/
process_class::process_class(){
  id = "id";
  name = "name";
  owner_uid = "owner_uid";
  parent_id = "parent_id";
  state = "state";
}

/*
regular 
process_class::process_class(std::string id, std::string name, std::string owner_uid, std::string parent_id, std::string state){
  this->id = id;
  this->name = name;
  this->owner_uid = owner_uid;
  this->parent_id = parent_id;
  this->state = state;
}

std::string process_class::get_id(){
  return id;
}

std::string process_class::get_name(){
  return name;
}

std::string process_class::get_owner_uid(){
  return owner_uid;
}

std::string process_class::get_parent_id(){
  return parent_id;
}

std::string process_class::get_state(){
  return state;
}

void process_class::to_string(){
  std::cout << "Process Name: " << process_class::get_name() << "\t"<< process_class::get_id() << "\t " << process_class::get_parent_id() << "\t" << process_class::get_owner_uid() << " " << process_class::get_state() <<  std::endl;
}
