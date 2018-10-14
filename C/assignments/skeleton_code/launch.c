#include "launch.h"

short launch(struct command *cmd) 
{
  short status;
  int fd[2];
  pid_t pid, wpid;
  int i;


  //pipe before forking

  for (i = 0; i < cmd[0].nchunk; i++){
    if(pipe(fd) < 0){
      perror("pipe error");
    }

    pid = fork();

    //child
    if(pid == 0){
      if (execvp(cmd[i].args[0], cmd[i].args) == -1){
        perror(" command error fork");
      }
      exit(EXIT_FAILURE);
    } else if(pid < 0){
      //error forking 
      perror("actually fork");
    } else {
      //parent
      do {
        int childstatus;
        wpid = waitpid(pid, &childstatus, 0);
      } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
  }
return 1;
}

