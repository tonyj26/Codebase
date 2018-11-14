#include "launch.h"

short launch(struct command *cmd)
{
  int status;
  int i;

  if (cmd[0].nchunks == 1){
    // set file descriptors
    cmd[0].fds[STDIN_FILENO] = STDIN_FILENO;
    cmd[0].fds[STDOUT_FILENO] = STDOUT_FILENO;

    // if only 1 command then execute with no pipes
    status = exec_com(cmd[0], NULL);
  }
  else {
    int pipe_count = cmd[0].nchunks -1;

    // allocate memory for pipes
    int (*pipes)[2] = calloc(pipe_count * sizeof(int[2]), 1);

    // err check
    if(pipes == NULL){
      perror("pipe");
    }

    // set pipes read write for each command chunk
    cmd[0].fds[STDIN_FILENO] = STDIN_FILENO;
    for (i = 1; i < cmd[0].nchunks; i++){
      pipe(pipes[i-1]);
      cmd[i-1].fds[STDOUT_FILENO] = pipes[i-1][1];
      cmd[i].fds[STDIN_FILENO] = pipes[i-1][0];
    }
    cmd[pipe_count].fds[STDOUT_FILENO] = STDOUT_FILENO;

    // exec each chunk
    for (i = 0; i < cmd[0].nchunks; i++){
      status = exec_com(cmd[i], pipes);
    }

    // close pipes
    for (i = 0; i < pipe_count; i++) {
      close(pipes[i][0]);
      close(pipes[i][1]);
    }

    // wait for each child to finish
    for (i = 0; i < cmd[0].nchunks; ++i){
      wait(NULL);
    }

    free(pipes);
  }
  return status;
}

short exec_com(struct command cmd, int (*pipes)[2])
{
  pid_t child;

  // fork each command
  child = fork();

  //child
  if (child == 0){
    int input_fd = cmd.fds[0];
    int output_fd = cmd.fds[1];
    if (input_fd != -1 && input_fd != STDIN_FILENO){
      dup2(input_fd, STDIN_FILENO);
    }

    if (output_fd != -1 && output_fd != STDOUT_FILENO){
      dup2(output_fd,STDOUT_FILENO);
    }

    if (pipes != NULL) {
      int num_pipes = cmd.nchunks - 1;

      for(int i = 0; i < num_pipes; i++){
        close(pipes[i][0]);
        close(pipes[i][1]);
      }
    }

    if(execvp(cmd.args[0], cmd.args) == -1){
      perror("shell");
      exit(1);
    }
    free(pipes);
  }
  return child;
}
