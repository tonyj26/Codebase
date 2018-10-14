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

short launch(struct command *);

#endif
