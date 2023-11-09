#include <stdio.h>

int main() {
    FILE *archivoEntrada = fopen("emails.csv", "r");
    FILE *archivoSalida = fopen("177195.txt", "w");

    if (archivoEntrada == NULL || archivoSalida == NULL)// Checa si hay algún error el la apertura del archivo
	{
        perror("Error al abrir el archivo");//Imprime mensaje del error
        return 1;
    }

    // Leer y descartar la primera línea con los encabezados
    char buffer[1000];
    fgets(buffer, sizeof(buffer), archivoEntrada);

    // Variables para almacenar las sumas de cada columna
    long long suma_columnas[5172] = {0}; // Usamos long long para evitar desbordamientos

    // Iterar sobre las filas desde 1 hasta 3000
    for (int fila = 1; fila <= 3000; fila++) 
	{
        // Descartar las letras de la columna
        fscanf(archivoEntrada, "%*[^,],");

        // Leer y sumar los valores desde "the" hasta la última columna
        for (int columna = 2; columna <= 5172; columna++) 
		{
            int valor;
            fscanf(archivoEntrada, "%d,", &valor);
            
            // Sumar al total de la columna
            suma_columnas[columna - 1] += valor;
        }

        // Moverse a la siguiente línea
        fscanf(archivoEntrada, "\n");
    }

    // Imprimir las sumas en el archivo de salida
    for (int columna = 1; columna <= 5172; columna++) {
        fprintf(archivoSalida, "Suma Columna %d: %lld\n", columna, suma_columnas[columna - 1]);//Para imprimir un valor long long
    }

    // Cerrar los archivos
    fclose(archivoEntrada);
    fclose(archivoSalida);

    printf("Operación completada con éxito.\n");

    return 0;
}

