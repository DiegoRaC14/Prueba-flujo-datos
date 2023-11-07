#include  <stdio.h>

int main (){
	
	char caracter; //Declarando variable tipo char
	FILE*file=fopen("Funciones ejercicio 9.cpp","r");
	
	if (file==NULL)
	{
		perror("Error en la apertura del archivo");
		return 1;
	}
	
	while (feof(file)==0)
	{
		caracter = fgetc(file);
		printf("%c",caracter);
		
	}
	
	fclose(file);
	printf("\n\nTodo esta viento en popa....\n\n\n");
	
	return 0;
}
