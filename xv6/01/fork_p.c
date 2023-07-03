/*
 * p.9
 */


#include <stdio.h>


int main(){
  printf("fork 関数はプロセスのコピーを作成する。\n");

  int pid = fork();

  
  if(pid > 0){
    printf("親プロセスでのforkの返り値は子プロセスのPIDになる\n");
    printf("子プロセスでのforkの返り値は0になる\n\n");
    printf("親プロセスが走るところです: pid=%d\n", pid);

  }else if(pid == 0){
    printf("子プロセスが走るところです: pid=%d\n", pid);
  }
  else{
    printf("エラーです");
  }
  return 0;
}
