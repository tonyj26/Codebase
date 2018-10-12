#include "launch.h"

short launch(char **args) 
{
  short status;
  int fd[2];
  int piped = 0;
  pid_t pid, wpid;
  char input[64], output[64];


  //pipe before forking
  if(pipe(fd) < 0){
    perror("fatal error");
  }

  pid = fork();
  for (int i = 0; args[i] != NULL; i++){
    if(strcmp(args[i], "|") == 0){
      args[i] = NULL;
      int piped = 2;
    }
  }


  //child
  if(pid == 0){
    if (piped){
      if(dup2(fd[0], STDIN_FILENO)<0) {
        perror("can't dup");
        exit(1);
      }
    }

    if(execvp(args[0], args) == -1){
      perror("bash");
    }
    exit(EXIT_FAILURE);
    //failed
  } else if (pid < 0) {
    perror("bash");
  }
  else {
    //parent
    if(piped){
      if(dup2(fd[1], STDOUT_FILENO) < 0){
        perror("can't dup");
        exit(1);
      }
    }
//    if(execvp(args[0], args) == -1){
  //    perror("bash");
   // }
    do {
      int childstatus;
      wpid = waitpid(pid, &childstatus, 0);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}

