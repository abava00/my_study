#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


#define MAX 256

// ToDo
// write %
// get commands
// wait for command execution end
// write %
//


int main(int argc, char *argv[]) {
  char *command[1];

  printf("(pid:%d)>", (int) getpid());

  while(1){
    scanf("%s", command[0]);
    command[1] = NULL;

    int task = fork();
    if(task < 0){
      printf("something error\n");
      exit(1);
    }
    else if(task == 0){
      // child
      execvp(command[0], command); printf("%s", command[0]);
    }
    else{
      //  parent
      int rc_wait = wait(NULL);
      printf("(pid:%d)>", (int) getpid());
    }
  }

  return 0;
}
