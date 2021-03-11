#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>

int tablero[9][9];
int revisado_rows;
int revisado_cols;
int revisado_squares;
/*validacion de rows */
void *validarRows( void *param){
	int j,k;
	for (j = 0;j<9;j++){
		int revisar_nums[] = {1,2,3,4,5,6,7,8,9};
		for (k = 0;k<9;k++){
			if (tablero[j][k] > 9 || revisar_nums[tablero[j][k]-1] != tablero[j][k]){
				revisado_squares = 0;
			}
		}
		
		revisar_nums[tablero[j][k]-1] = 0;
	}
}

/*validacion de cols */ 
void *validarCols (void * param){
	int j,k;
	for (j=0;j<9;j++){
		int revisar_nums[] = {1,2,3,4,5,6,7,8,9};
		for (k=0;k<9;k++){
			if (tablero[j][k] >9 || revisar_nums[tablero[j][k]-1] != tablero[j][k]){
				revisado_cols = 0;
			}
		}
	}
}

/*validacion por squares*/
void *validarSquares (){
	int j,k,m;
	int counter = 0;

	do{
		int algo = 0;
		do{
			int revisar[9]= {0};
			int index = 0;
			for (j = 0 ; j<3 ; j++){
					
				for (k = 0 ; k<3 ;k++){
					tablero[j + counter][k + algo];
					
					printf("Tablero:  %d", tablero[j + counter][k + algo]);	
					revisar[index] = tablero[j+counter][k+algo];
					index++;
						
				}
						
			}
			
			/*if (revisar_valores(revisar)){
			revisado_squares = 0;
			} */
			
			algo += 3;
		}while(algo<9);
		counter += 3;
	}while(counter<9);
	
}

void revisar_valores(){
	bool uno = false;
	bool dos = false;
	bool tres = false;
	bool cuatro = false;
	bool cinco = false;
	bool seis = false;
	bool siete = false;
	bool ocho = false;
	bool nueve = false;
	

	
	/*if (uno && dos && tres && cuatro && cinco && seis && siete && ocho && nueve){
		
		
	}
	else:
		
		
		*/
}


int main(int argc, char* argv[]){
	

	if (argc < 2){
		printf("Numero de parametros incorrecto.\n");
	}
	/* Abrir el file */
	FILE *file;
	file = fopen(argv[1],"r");
	
	
	char numero [81]; /*numero de elementos del sudoku */
	int numeros [81];
	char ch;
	int i,j,k,w, counter,counter2;
	
	/*revisar si el archivo esta vacio */
	if (file == NULL){
	printf("Archivo Vacio\n");
	}
	
	/* obtener cada caracter */
	while ((ch = fgetc(file))!= EOF){
		numeros[counter] = ch - '0';
		counter++;
	}
	
	/*Meter digitos a 2d array */
	for (j = 0; j<9; j++){
		for(k = 0; k<9; k++){
		tablero[j][k] = numeros[counter2];
		/*printf("%d\n", tablero[j][k]);*/
		counter2++;
		}
	}
	
	validarSquares();
	
	
	
	fclose(file);
	
	
	return 0;

}

