/*
 *p.12
 */



#include <stdio.h>
#include <fcntl.h>

int main(){

  char *args[2];

  args[0] = "cat";
  args[1] = 0;

  if(fork() == 0 ){
    // 入力を閉じる
    close(0);
    // 入力を開き直す
    open("input.txt", O_RDONLY);
    execvp("cat", args);
  }

  return 0;
}
