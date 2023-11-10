#include <stdio.h>

int main() {
    FILE *archivoEntrada = fopen("emails.csv", "r");
    FILE *archivoSalida = fopen("177195.txt", "w");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Leer y descartar la primera l�nea con los encabezados
    char buffer[1000];
    fgets(buffer, sizeof(buffer), archivoEntrada);

    // Variables para almacenar las sumas de cada columna
    double suma_columnas[3000] = {0}; // Usamos double para permitir decimales

    // Iterar sobre las filas desde 1 hasta 3000
    for (int fila = 1; fila <= 3000; fila++) 
	{
        // Leer el nombre de la fila desde la primera columna
        fscanf(archivoEntrada, "%[^,],", buffer);

        // Descartar las letras de la columna
        fscanf(archivoEntrada, "%*[^,],");

        // Leer y sumar los valores de las columnas para las filas 195 a 245
        for (int columna = 1; columna <= 5172; columna++) 
		{
            double valor;
            fscanf(archivoEntrada, "%lf,", &valor);

            // Sumar al total de la columna si estamos en las filas 195 a 245
            if (fila >= 195 && fila <= 245) {
                suma_columnas[columna - 1] += valor;
            }
        }

        // Moverse a la siguiente l�nea
        fscanf(archivoEntrada, "\n");
    }

    // Imprimir las sumas en el archivo de salida
    for (int columna = 1; columna <= 3000; columna++) {
        fprintf(archivoSalida, "Suma Columna %d: %.2f\n", columna, suma_columnas[columna - 1]);
    }

    // Cerrar los archivos
    fclose(archivoEntrada);
    fclose(archivoSalida);

    printf("Todo esta viento en popa.\n");

    return 0;
}



