#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int matriz(int n);

int main ()
{
	FILE*archivo;
	archivo=fopen("archivo.txt","a");
	
	
	if (archivo==NULL){
		perror ("Error al crear el archivo\n");
		return 1;
	}
	
	//Ahora puedes escribir en el archivo
	fprintf(archivo, "Esto se agrega al archivo anterior.\n");
	
	//Cierra el archivo después de usarlo
	fclose(archivo);
	
	
	return 0;
}
