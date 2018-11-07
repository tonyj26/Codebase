/*
Kyle Cheung
process_main.cpp
October 4, 2018
*/
#include "process.h"
#include "processlist.h"

int main(){
  processlist_class processlist;
  processlist.populate();
  processlist.to_string();
  return 0;
}
