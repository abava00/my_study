/*
 * p.10
 */

#include <stdio.h>

int main(){
  
  char *argv[3];

  argv[0] = "echo";
  argv[1] = "hello world for xv6";
  argv[2] = 0;

  printf("exec関数は、今動いているプログラムを引数で指定したプログラムで上書きする。\n");

  execvp("/bin/echo", argv);
  
  // ここから下は読み込まれなくなるんだと思う

  printf("error\n");

  return 0;
}
