#include <stdio.h>

int main (){
	FILE*archivo;
	
	archivo=fopen("archivo.txt","w");
	
	if (archivo==NULL){
		perror ("Error al crear el archivo\n");
		return 1;
	}
	
	//Ahora puedes escribir en el archivo
	fprintf(archivo, "lll.\n");
	
	//Cierra el archivo después de usarlo
	fclose(archivo);
	
	
	return 0;
}
