#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t uno_t;
    pid_t dos_t;
    pid_t tres_t;
    clock_t start_t;
    clock_t end_t;
    clock_t resta_t;
    int  i = 0;
    int n = 0;
    int k = 0;

    start_t = clock();
    uno_t = fork();
    if (uno_t == 0){
        dos_t = fork();
        if (dos_t == 0){
            tres_t = fork();
            for(i; i<1000000; i++){
            }
        }else{
            wait(NULL);
            for(k; k<1000000; k++){
            }
        }
        wait(NULL);
        for(n; n<=1000000; n++){
        }
    }else{
        wait(NULL);
        end_t = clock();

        resta_t = (double)(end_t - start_t)/CLOCKS_PER_SEC;
        printf("%f\n", resta_t);
    }

    return(0);
}
