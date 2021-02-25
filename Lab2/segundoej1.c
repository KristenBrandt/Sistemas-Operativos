#include <stdio.h>

int main(){
  int i = 0;
  for (i; i==4; i++)
  {
    fork();
  }
  printf("forks\n");
}
