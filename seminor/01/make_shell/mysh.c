#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX 512

void child();
void parent();
char* read_line();
void text_convert(char *input);
void text_count(char* input);


int main(int argc, char *argv[]){

  char* line;
  // char* args[MAX];


  printf("(pid:%d)>", (int) getpid());
  fflush(stdout);

  for(int i = 0; i < 3;i++){

  /* shell */
  // line = strdup(read_line());
  line = "hello world"

  printf("\nread line: %s\n", line);
  fflush(stdout);

    int task = fork();
    if(task < 0){
      printf("something error\n");
      exit(1);
    }
    else if(task == 0){
      // child
      printf("hello, I am child (pid:%d)\n", (int) getpid());
      fflush(stdout);
      // child();
    }
    else{
      // parent
      int rc_wait = wait(NULL);
      printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", task, rc_wait, (int) getpid());
      // printf("(pid:%d)>", (int) getpid());
      // fflush(stdout);
      // parent();
      // line = strdup(read_line());
    }
  }

  return 0;
}


void child(){
      printf("start child\n");

      // execvp(arg[0], arg); 
      printf("end child\n");

}


void parent(){
      // int rc_wait = wait(NULL);
      printf("end parent\n");
      printf("(pid:%d)>", (int) getpid());
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
  // need this?

}
