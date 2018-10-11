//hostname_class.cpp
#include "hostname.h"
#include <iostream>
#include <unistd.h>
#include <limits.h>

using namespace std;

namespace hostnamespace
{
  hostname_class::hostname_class(){
    name[HOST_NAME_MAX];
    gethostname(name, HOST_NAME_MAX);
  }

  void hostname_class::to_string(){
    cout << "Hostname:" << name << endl;
  }
};

