#include "launch.h"

short launch(char **args) 
{
  short status;

  pid_t pid, wpid;
  pid = fork();
  if(pid == 0){
    if(execvp(args[0], args) == -1){
      perror("bash");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("bash");
  }
  else {
    do {
      int childstatus;
      wpid = waitpid(pid, &childstatus, 0);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}

