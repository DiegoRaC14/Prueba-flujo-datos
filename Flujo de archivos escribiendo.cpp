#include  <stdio.h>

int main (){
	
	FILE*file=freopen("line.txt","w",stdout);
	
	if (file==NULL)
	{
		perror("Error en la apertura del archivo");
		return 1;
	}

	//Ahora puedes escribir en el archivo
	fprintf(archivo, "Esto se agrega al archivo anterior.\n");
	
	//Cierra el archivo después de usarlo
	fclose(file);
	
	return 0;
}
