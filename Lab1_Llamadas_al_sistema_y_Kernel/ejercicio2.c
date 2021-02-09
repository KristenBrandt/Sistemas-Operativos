#include<stdio.h>
#include <stdlib.h>
// código tomado de: http://cbasicprogram.blogspot.com/2012/05/file-copy-using-command-line-arguments.html

int main(int argc,char *argv[])
{
 FILE *fs,*ft;
 int ch;
 if(argc!=3)
 {
  printf("Numero de argumentos invalidos.");
  return 1;
 }
 fs=fopen(argv[1],"r");
 if(fs==NULL)
 {
  printf("No se pudo encontrar el archivo.");
  return 1;
 }
 ft=fopen(argv[2],"w");
 if(ft==NULL)
 {
  printf("No se puede abrir el segundo archivo");
  fclose(fs);
  return 1;
 }

 while(1)
 {
  ch=fgetc(fs);
  if (feof(fs)) break;
  fputc(ch,ft);
 }

 fclose(fs);
 fclose(ft);
 return 0;
}
