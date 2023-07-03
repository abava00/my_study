#include <stdio.h>

int main(){
  printf("file descriptor はプログラムの出力先を指定する整数。\n");
  printf("0:  標準入力\n");
  printf("1:  標準出力\n");
  printf("2:  エラー出力\n");
  printf("3~: 任意\n");

  char buf[512];
  int n;

  n = read(0, buf, sizeof(buf));

  printf("read関数 は文字を読み込む、戻り値は読み込んだバイト数。n = %d\n", n);
  
  write(1, buf, sizeof(char[n]));
  write(2, buf, sizeof(char[n]));

  return 0;
}
