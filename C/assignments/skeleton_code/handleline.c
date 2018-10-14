#include "handleline.h"

struct command *handleline(char *line)
{
  int nchunks = 1;
  int i;
  int curchunk;

  //counts command chunks
  for (i = 0; i < strlen(line); i++){
    if (line[i] == '|' && (line[i] != strlen(line) - 1)){
      nchunks++;
    }
    else if (line[i] == '|' && (i == 0 || strlen(line) -1)){
      exit(1);
    }
  }
  struct command *commands = malloc(nchunks * sizeof(struct command));
  for (int curchunk = 0; curchunk < nchunks; curchunk++){
    char *chunk;
    if (curchunk == 0){
      chunk = strtok(line, "|");
    }
    else {
      chunk = strtok(NULL, "|");
    }
    commands[curchunk].args = tokenize(chunk);
    commands[curchunk].nchunk = nchunks;
  } 

  return commands;
}

