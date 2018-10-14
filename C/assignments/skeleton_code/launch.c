#include "launch.h"

short launch(struct command *cmd) 
{
  short status;
  int fd[2];
  pid_t pid, wpid;


  //pipe before forking
  if(pipe(fd) < 0){
    perror("fatal error");
  }

  pid = fork();

  //child
  if(pid == 0){

    if(execvp(cmd[0].args[0], cmd[0].args) == -1){
      perror("bash");
    }
    exit(EXIT_FAILURE);
    //failed
  } else if (pid < 0) {
    perror("bash");
  }
  else {
    //parent
    do {
      int childstatus;
      wpid = waitpid(pid, &childstatus, 0);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}

