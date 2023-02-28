#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX 512

void child(char *input);
void parent();
char *read_line();
void text_convert(char *input, int count);
void check_keyword(char args);


int main(int argc, char *argv[]){

  char *line;

  while(1){
    printf("(pid:%d)>", (int) getpid());
    fflush(stdout);

    /* shell */
    line = strdup(read_line());

    int rc = fork();
    if(rc < 0){
      printf("something error\n");
      exit(1);
    }
    else if(rc == 0){
      // child
      child(line);
      free(line);
    }
    else{
      // parent
      int rc_wait = wait(NULL);
      parent();
      free(line);
    }
  }

  return 0;
}


void child(char *input){

      char line[MAX];
      char *cmdline;
      int i = 0;

      strcpy(line, input);
      // printf("cmdline: %s\n", line);
      
      char *args[MAX];  

      
      // DEBUG
      // for(int c = 0; c < counter; c++){
      //   printf("args[%d]: %s\n", c, args[c]);
      // }
      
      cmdline = strtok(line, " ");
      args[i] = strdup(cmdline);
      // printf("text %d: %s\n",i, args[i]);
      i++;

      while(cmdline != NULL){
        cmdline = strtok(NULL, " ");
        if(cmdline == NULL){
          break;
        }
        else{
          args[i] = strdup(cmdline);
          // printf("text %d: %s\n",i, cmdline);
          // printf("text %d: %s\n",i, args[i]);
        }
        i++;
      }
      

      args[i] = NULL;

      if (execvp(args[0], args) == -1){
        printf("fault\n");
      }
      else{
        printf("success\n");
      }
      
      for(int j = 0; j < MAX; j++){
        free(args[j]);
      }

}


void parent(){
                                  
                                             
}

char *read_line(){
  /*
   * 1: 入力の読み取り
   * 2: 入力文字数分だけ戻り値のメモリ確保
   * */

  char buf[MAX];
  char* command;
  memset(buf, '\0', sizeof(buf));

  // 1: 入力の読み取り
  read(0, buf, sizeof(buf));

  // 2: 入力文字数分だけ戻り値のメモリ確保
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


void check_keyword(char args){
  // search < > | & 
  
  // when |

  // when &
  
}
