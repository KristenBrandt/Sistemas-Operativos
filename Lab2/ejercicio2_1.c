#include <stdio.h>
#include <time.h>

int main(){
  clock_t uno_t;
  clock_t dos_t;
  clock_t resta_t;
  int i;
  int n;
  int k;

  uno_t = clock();
  for (i=0; i<1000000; i++){
  }
  for (n=0; n<1000000; n++){
  }
  for (k=0; k<1000000; k++){
  }
  dos_t = clock();
  resta_t = (double) (dos_t-uno_t)/CLOCKS_PER_SEC;
  printf("Tiempo total tomado %f \n", resta_t );
}
