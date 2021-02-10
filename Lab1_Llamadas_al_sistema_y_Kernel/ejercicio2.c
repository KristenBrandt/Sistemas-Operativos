#include <stdio.h>
//https://www.programmingc.net/index.php/en/advanced/copy-file-command-line
int main(int argc, char *argv[]){
    FILE *file1, *file2;
    char ch;
    //clrscr();
    if(argc == 3){
        file1 = fopen(argv[1],"r");
        file2 = fopen(argv[2],"w");
        do{
            ch = fgetc(file1);
            fputc(ch,file2);
        }while(ch!=EOF);//EOF = End of File
        printf("\nArchivo de %s copiado a %s", argv[1], argv[2]);
        fclose(file1);
        fclose(file2);
        return 0;
    }
    else{
        printf("\nNumero de argumentos invalidos");
        printf("\nNo se logro copiar el archivo");
        return 1;
    }
}
