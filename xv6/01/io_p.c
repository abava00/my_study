/*
 * p.14
 * https://laboradian.com/cmd-to-move-fd2-to-fd1/
 */


#include <stdio.h>
#include <fcntl.h>

int main(){

  char *args[4];
  args[0] = "ls";
  args[1] = "tmp";
  args[2] = "temp";
  args[3] = 0;

  char buf[512];

  if(fork() == 0){
    // fd2を閉じる
    close(2);
    // 標準出力をfd2に複製する
    dup(1, 2);

    execvp("/bin/ls", args);
  }else{
    wait(0);

  }

  return 0;
}
