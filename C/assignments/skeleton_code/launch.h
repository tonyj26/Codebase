#ifndef LAUNCH_H
#define LAUNCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "helper.h"
#include "handleline.h"
#include <sys/stat.h>
#include <fcntl.h>

short launch(struct command *);
short exec_com(struct command , int (*)[2]);

#endif
