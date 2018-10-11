//hostname.h
#pragma once 

namespace hostnamespace
{
  class hostname_class
  {
    public:
      hostname_class();
      void to_string();

    private:
      char *name;
  };
}
