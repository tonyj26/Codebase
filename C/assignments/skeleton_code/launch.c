#include "launch.h"

short launch(struct command *cmd) 
{
  short status;
  int fd[2];
  pid_t pid, wpid, p2;
  int i;

  for (i = 0; i < cmd[0].nchunks; i++){
    if(pipe(fd) < 0){
      perror("pipe error");
    }

    pid = fork();

    //child
    if(pid == 0){

      close(fd[1]);
      if (dup2(fd[0], STDIN_FILENO) < 0){
        perror("shell can't dup");
        exit(1);
      }
      close(fd[0]);

      if (execvp(cmd[i].args[0], cmd[i].args) == -1){
        perror(" command error fork");
      }
      exit(EXIT_FAILURE);
    } else if(pid < 0){
      //error forking 
      perror("actually fork");
    } else {
      //parent
      p2 = fork();

      if (p2 < 0){
        perror("fork");
      }

      if (p2 == 0) {

        close(fd[0]);
        if(dup2(fd[1],STDOUT_FILENO) < 0){
          perror("can't dup");
          exit(1);
        }
        close(fd[1]);


        if (execvp(cmd[i].args[0], cmd[i].args) == -1){
          perror("command error");
        }
      }
      else {
        do {
          int childstatus;
          wpid = waitpid(pid, &childstatus, 0);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
      }
      do {
        int childstatus;
        wpid = waitpid(pid, &childstatus, 0);
      } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
  }
  return 1;
}

