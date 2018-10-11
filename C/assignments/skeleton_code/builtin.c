
#include "builtin.h"

char *builtin_str[] = {
  "cd",
  "exit"
};

int (*builtin_func[]) (char **) = {
  &cd,
  &exit_shell
};

int num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

int cd(char **args)
{
  if(args[1] == NULL){
    fprintf(stderr, "expected argument to \"cd\"\n");
  } else {
    if(chdir(args[1]) != 0) {
      perror("sh");
    }
  }
  return 1;
}

int exit_shell(char **args){
  return -1;
}


