
#include "tokenize.h"
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

int tokenize(char *line, char *args[], int maxargs)
{
  int n = 0;
  while (*line && isspace(*line)){
    line++;
  }

  while(*line && n < maxargs)
  {
    args[n++] = line;
    while (*line && !isspace(*line)){
      line++;
    }
    while(*line && isspace(*line)){
      *(line++) = 0;
    }
  }
  args[n] = NULL;
  return n;
}

