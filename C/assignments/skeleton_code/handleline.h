#ifndef HANDLELINE_H
#define HANDLELINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenize.h"

struct command 
{
  char **args;
  int nchunk;
};


struct command *handleline(char *);

#endif
