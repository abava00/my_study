#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX 512

void child(char* input);
void parent();
char* read_line();
void text_convert(char* input, int count);


int main(int argc, char *argv[]){

  char* line;
  // char* args[MAX];

  while(1){
  printf("(pid:%d)>", (int) getpid());
  fflush(stdout);


  /* shell */
  line = strdup(read_line());

  // printf("\nread line: %s\n", line);

    int rc = fork();
    if(rc < 0){
      printf("something error\n");
      exit(1);
    }
    else if(rc == 0){
      // child
      // printf("hello, I am child (pid:%d)\n", (int) getpid());
      child(line);
    }
    else{
      // parent
      int rc_wait = wait(NULL);
      // printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
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
      int i = 0;

      strcpy(line, input);
      printf("cmdline: %s\n", line);

      int counter = 0; 


      char *temp;
      temp = strtok(line, " ");
      while(temp != NULL){
        temp = strtok(NULL, " ");
        if(temp == NULL){
          break;
        }else{
          counter++;
        }
      }
      printf("%d", counter);
     
      char *args[counter + 1];  for(int j = 0; j < counter; j++){ args[j] = NULL; }
      

      cmdline = strtok(line, " ");
      args[i] = strdup(cmdline);
      printf("text %d: %s\n",i, args[i]);
      i++;

      while(cmdline != NULL){
        cmdline = strtok(NULL, " ");
        if(cmdline == NULL){
          break;
        }else{
          args[i] = strdup(cmdline);
          // printf("text %d: %s\n",i, cmdline);
          printf("text %d: %s\n",i, args[i]);
        }
        i++;
      }
      
      // char *myargs[2];
      // myargs[0] = strdup("ls");
      // myargs[1] = NULL;
      // execvp(myargs[0], myargs);
      
      
      args[counter + 1] = NULL;
      for(int c = 0; c < counter; c++){
        printf("args[%d]: %s\n", c, args[c]);
      }

      if (execvp(args[0], args) == -1) {
        printf("fault\n");
      }else{
        printf("success\n");
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
  command = (char*)malloc(strlen(buf) * sizeof(char));
  
  strcpy(command, buf);

  text_convert(command, strlen(buf));

  return command;
}

void text_convert(char *input, int count){
  
  int isnewline = 0;

  for(int i = 0; i < count; i++){
    if(input[i] == '\n'){
      isnewline = 1;
      input[i] = '\0';
    }
    if(isnewline){
      input[i] = '\0';
    }
    // printf("input:%c\n", input[i]);
  }

}
