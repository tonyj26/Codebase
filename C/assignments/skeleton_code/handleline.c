#include "handleline.h"

struct command *handleline(char *line)
{
  int nchunks = 1;
  int i;
  int curchunk;
  char *saveptr;
  int in = 0;
  int out = 0;

  //counts command chunks
  for (i = 0; i < strlen(line); i++){
    if ((line[i] == '|' ) && (line[i] != strlen(line) - 1)){
      nchunks++;
    }

    else if ((line[i] == '|' ) && (i == 0 || strlen(line) -1)){
      exit(1);
    }
  }
  struct command *commands = malloc(nchunks * sizeof(struct command));
  for (curchunk = 0; curchunk < nchunks; curchunk++){
    char *chunk;
    if (curchunk == 0){
      chunk = strtok_r(line, "|<>", &saveptr);
    }
    else {
      chunk = strtok_r(NULL, "|><", &saveptr);
    }

    char *ptr = chunk;
    char last = ' ';
    int toks = 1;
    while(*ptr){
      if (isspace(*ptr) && !isspace(last)) {
        toks++;
      }
      last = *ptr;
      ptr++;
    }
    commands[curchunk].args = malloc((toks + 1) * sizeof(char *));
    commands[curchunk].argc = toks;
    commands[curchunk].nchunks = nchunks;

    tokenize(chunk, commands[curchunk].args, commands[curchunk].argc);
  } 

  return commands;
}

void free_commands(struct command *cmds, int len)
{
  int i;
  for (i = 0; i < len; i++) {
    free(cmds[i].args);
  }
}
