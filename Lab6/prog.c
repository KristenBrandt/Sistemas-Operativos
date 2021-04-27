#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/syscall.h>

#define gettid() syscall(SYS_gettid)
#define loop 15
#define thread_num 20

sem_t semaforo;

struct log {
	FILE* rchivo;
};

void* cuenta_threads(void *numero){
	int k;
	int id_thread = gettid();
	fprintf(((struct log *)numero)->rchivo, "Iniciando thread %d\n", id_thread);//write file
	fprintf(((struct log *)numero)->rchivo, "%d - Semaforo abierto con exito\n", id_thread);//write file
	for (k = 0; k < loop; ++k){
		fprintf(((struct log *)numero)->rchivo, "Iniciando interacion %d\n", k+1);//write file
		sem_wait(&semaforo);
		fprintf(((struct log *)numero)->rchivo, "%d - (!) Recurso tomado\n", id_thread);//write file
		fprintf(((struct log *)numero)->rchivo, "%d - Buenos dias! Recuso usado\n", id_thread);//write file
		sleep(10);
		fprintf(((struct log *)numero)->rchivo, "%d - Recurso devuelto :) \n", id_thread);//write file
		sem_post(&semaforo);
	}
	fprintf(((struct log *)numero)->rchivo, "Finalizando thread %d\n", id_thread);//write file
	return NULL;
}

int main(){
	pthread_t threads_1[thread_num];
	int m;
	FILE *ar;
	ar = fopen("Archivo1.txt", "w"); //open file
	struct log *archivo = (struct log *)malloc(sizeof(struct log));
	archivo -> rchivo = ar;
	if (ar != NULL){
		fprintf(ar,"Iniciando programa\n"); //write file
		fprintf(ar,"Creando threads\n"); //write file	
	}
	sem_init(&semaforo,0, 1); //1 siendo la cantidad de recursos
	
	for (m = 0; m< thread_num; m++){
		pthread_create(&threads_1[m], NULL, *cuenta_threads, (void *)archivo);
	}
	
	fclose(ar); //close file
};
