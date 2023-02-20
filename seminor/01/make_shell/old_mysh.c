#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


#define MAX 512

// ToDo
// write %
// get commands
// wait for command execution end
// write %
//

char* find_args(char buf);


int main(int argc, char *argv[]) {
  // char *command[4];
  char *arg[MAX];
  char buf[MAX]; for(int i = 0; i < sizeof(buf); i++){ buf[i] = '\0'; }
  char word[MAX];for(int i = 0; i < sizeof(word); i++){ word[i] = '\0'; }

  int n;

  printf("(pid:%d)>", (int) getpid());
  fflush(stdout);

  while(1){
    n = read(0, buf, sizeof buf);
    printf("%s\n", buf);
    fflush(stdout);



    // find arg
    int c = 0;
    int count = 0;
    for(int i = 0; i < sizeof(buf); i++){
      // printf("%c", buf[i]);
      // fflush(stdout);

      // if(buf[i] == ' ' || buf[i] == '\0'){
      if(buf[i] == ' '){
        // printf("find\n");
        // fflush(stdout);
        // strcpy(arg[count], word);
        // arg[count] = word;
        if(MAX <= count) break;
        arg[count] = strdup(word);
        // printf("args[%d]= %s \n",count, args[count]);
        // fflush(stdout);
        count++;
        for(int j = 0; j < sizeof(word); j++){ word[j] = '\0'; }
        c = 0;
        i++;
      }
      else if(buf[i] == '\n'){
      printf("kaigyou\n");
      fflush(stdout);
        buf[i] = '\0';
      }
      word[c] = buf[i];
      c++;
    }


    // for(int l = 0; l < count; l++){
      // printf("count%d: %s",count, arg[l]);
      // fflush(stdout);
    // }
 
  

    int task = fork();
    if(task < 0){
      printf("something error\n");
      exit(1);
    }
    else if(task == 0){
      // child
      printf("hello, I am child (pid:%d)\n", (int) getpid());
      fflush(stdout);
      printf("start child\n");
      printf("arg  0: %s\n", arg[0]);
      fflush(stdout);
      // arg[1] = NULL;

      execvp(arg[0], arg); 

      printf("arg  0: %s\n", arg[0]);
      fflush(stdout);



    }
    else{
      //  parent
      int rc_wait = wait(NULL);
      printf("end parent\n");
      printf("(pid:%d)>", (int) getpid());
    }
  }

  return 0;
}

