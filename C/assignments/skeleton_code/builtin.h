
#ifndef BUILTIN_H
#define BUILTIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int num_builtins();
int cd(char **);
int exit_shell(char **);

#endif

