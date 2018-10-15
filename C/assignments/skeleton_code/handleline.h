#ifndef HANDLELINE_H
#define HANDLELINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenize.h"
#include <ctype.h>

struct command 
{
  char **args;
  int argc;
  int nchunks;
};

struct command *handleline(char *);
void free_commands(struct command *, int);

#endif
