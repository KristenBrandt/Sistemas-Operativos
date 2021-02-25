#include <stdio.h>
int main(){
  fork();
  int i = 0;
  if (fork()== 0){
    for (i; i<=4000000; i++){
        printf("%d\n",i );
    }
  }
  else{
    while(1){

    }
  }
  return (0);
}
