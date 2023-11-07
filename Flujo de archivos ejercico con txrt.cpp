#include <stdio.h>

int main (){
	
	char caracter; //Declarando variable tipo char
	int count;
	bool condition;
	FILE*file=fopen("line.txt","r");
	
	if (file==NULL)
	{
		perror("Error en la apertura del archivo");
		return 1;
	}
	
	count = 0;
	condition = false;
	
	while (feof(file) == 0)
	{
		caracter = fgetc(file);
		
		if (caracter=='\n')
			condition=true;
		
		if (!condition)
		if (caracter ==',')
			count++;
		
	}
	
	printf("%d",count);
	
	fclose(file);
	printf("\n\nTodo esta viento en popa....\n\n\n");
	
	return 0;
}
