#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX 512

void child(char* input);
void parent();
char* read_line();
void text_convert(char* input);
void text_count(char* input);


int main(int argc, char *argv[]){

  char* line;
  // char* args[MAX];

  while(1){
  printf("(pid:%d)>", (int) getpid());
  fflush(stdout);


  /* shell */
  line = strdup(read_line());

  // printf("\nread line: %s\n", line);
  // fflush(stdout);

    int rc = fork();
    if(rc < 0){
      printf("something error\n");
      exit(1);
    }
    else if(rc == 0){
      // child
      // printf("hello, I am child (pid:%d)\n", (int) getpid());
      fflush(stdout);
      child(line);
    }
    else{
      // parent
      int rc_wait = wait(NULL);
      // printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
      fflush(stdout);
      // printf("(pid:%d)>", (int) getpid());
      parent();
      // line = strdup(read_line());
    }
  }

  return 0;
}


void child(char* input){
      printf("start child\n");

      char line[MAX];
      char *cmdline;
      char *args[MAX];
      int i = 0;

      strcpy(line, input);
      printf("cmdline: %s", line);
      fflush(stdout);
      
      

      cmdline = strtok(line, " ");
      args[i] = strdup(cmdline);
      printf("text %d: %s\n",i, args[i]);
      i++;

      printf("test\n");
      fflush(stdout);


      while(cmdline != NULL){
        cmdline = strtok(NULL, " ");
        args[i] = strdup(cmdline);
        printf("text %d: %s\n",i, args[i]);
        fflush(stdout);
        i++;
      }
      
      // ?????????????????????????????????????
      printf("test\n");
      fflush(stdout);

      char *myargs[2];
      myargs[0] = strdup("ls");
      myargs[1] = NULL;
      execvp(myargs[0], myargs);
      fflush(stdout);
      
      // execvp(args[0], args);
      if (execvp(args[0], args) == -1) {
        printf("fault\n");
        fflush(stdout);
      }else{
        printf("success\n");
        fflush(stdout);
      }
      

      // execvp(arg[0], arg); 
      printf("end child\n");

}


void parent(){
      printf("start parent\n");
      // int rc_wait = wait(NULL);
      // printf("(pid:%d)>", (int) getpid());
      printf("end parent\n");
}

char* read_line(){
  /*
   * 1: 入力の読み取り
   * 2: 入力文字数分だけ戻り値のメモリ確保
   * */

  // char *buf = malloc(sizeof(char) * MAX);
  char buf[MAX];
  char* command;
  memset(buf, '\0', sizeof(buf));

  // 1: 入力の読み取り
  read(0, buf, sizeof(buf));

  // 2: 入力文字数分だけ戻り値のメモリ確保
  // printf("%s\n", buf);
  // printf("count: %d\n", strlen(buf));
  // fflush(stdout);
  command = (char*)malloc(strlen(buf) * sizeof(char));
  strcpy(command, buf);

  text_convert(command);

  return command;
}

void text_convert(char *input){

}
