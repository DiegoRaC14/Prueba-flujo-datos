#include <stdio.h>

#define FILAS 5172
#define COLUMNAS 3000

int main() {
    int arreglo[FILAS][COLUMNAS]; // Arreglo declarado

    FILE *file;
    file = fopen("emails.csv","r"); // Abrir el archivo en modo lectura

    if (file == NULL) // Si el archivo marca error
    {
        perror("Error en la apertura del archivo"); // Se usa para imprimir mensajes de error
        return 1;
    }

    int fila = 1;

    while (!feof(file)) // Mientras la función regrese un 0 todavía hay contenido en el documento
    {
        if (ferror(file)) // En caso de que haya un error en el archivo
        {
            printf("Error al leer el archivo.\n");
            return 1;
        }

        for (int i = 0; i < COLUMNAS; i++) 
		{
            if (fscanf(file, "%d", &arreglo[fila][i]) == EOF) 
                break; // Se detiene el loop si ya se finalizó la línea
        
        }

        fila++; // Cuando termina la primera línea aumenta en uno para pasar a la segunda

        if (fila == FILAS)
            break;
    }

    

    /* Imprimir la matriz */
    for (int i = 0; i < FILAS; i++) 
	{
        for (int j = 0; j < COLUMNAS; j++) 
		{
            printf("%d ", arreglo[i][j]);
        }
        printf("\n");
    }
    printf("\nTodo está viento en popa... \n\n\n");
	fclose(file); // Cierra el flujo
    return 0;
}

