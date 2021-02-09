#include <stdio.h>
#include <inistd.h>

int main(){

	int f = fork();

	if(f == 0){
			printf("%d\n",(int)getpid());
			execl("hello_world", (char*)NULL);
	}
	else{
			printf("%d\n", (int)getpid());
			execl("hello_world", (char*)NULL);

	}
}
