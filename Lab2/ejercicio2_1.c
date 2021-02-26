#include <stdio.h>
#include <time.h>

int main(){
  clock_t uno_t;
  clock_t dos_t;

  int i;
  int n;
  int k;

  uno_t = clock();
  for (i=0; i<1000000; i++){
  printf("%d\n",i);
  }
  for (n=0; n<1000000; n++){
  printf("%d\n", n);
  }
  
  for (k=0; k<1000000; k++){
  printf("%d\n",k);
  }
  dos_t = clock();
 
 
  double resta = dos_t-uno_t;
  
  printf("Tiempo total tomado %f \n", resta );
}
