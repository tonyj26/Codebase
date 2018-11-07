/*
Kyle Cheung
processlist_class.cpp
October 4, 2018
*/
#include "processlist.h"

/*
default constructor
grabs all processes and pushes their name onto the dir_list
*/
processlist_class::processlist_class(){
  if ((dir = opendir ("/proc")) != NULL){
    while ((ent = readdir (dir)) != NULL) {
      std::string process(ent->d_name);
      if(isdigit(process[0])){
        dir_list.push_back(process);
      }
    }
  }
  closedir(dir);
}

std::vector<process_class> processlist_class::populate(){
  for( std::vector<std::string>::iterator it = dir_list.begin(); it != dir_list.end(); ++it){
    if ((dir = opendir (("/proc/" + *it).c_str() )) != NULL){

      inFile.open("/proc/" + *it + "/status");
      while(getline(inFile, line)){
        if(line.find("State", 0) == 0 ){
          state = line.c_str();
        }
        if(line.find("Pid", 0) == 0 ){
          pid = line.c_str();
        }
        if(line.find("PPid", 0) == 0){
          ppid = line.c_str();
        }
        if(line.find("Uid", 0) == 0){
          uid = line.c_str();
        }
      }
      process_class obj( pid , *it, uid, ppid, state);
      list.push_back(obj);
      inFile.close();
    }
  }
  return list;
}

void processlist_class::to_string(){
  for(std::vector<process_class>::iterator it = list.begin(); it != list.end(); ++it){
    (*it).to_string();
  }
}
