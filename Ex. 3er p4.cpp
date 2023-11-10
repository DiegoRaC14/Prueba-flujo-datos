#include <stdio.h>

// Definir el tamaño de la tabla
#define FILAS 5172
#define COLUMNAS 3000

// Definir el rango de filas a sumar
#define INICIO 195
#define FIN 245

int main() {
    FILE *archivoEntrada = fopen("emails.csv", "r");
    FILE *archivoSalida = fopen("177195.txt", "w");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Declarar una matriz para almacenar los datos de la tabla
    int datos[FILAS][COLUMNAS];

    // Declarar un arreglo para almacenar las sumas de cada columna
    int sumas[COLUMNAS];

    // Inicializar las sumas en cero
    for (int i = 0; i < COLUMNAS; i++) {
        sumas[i] = 0;
    }

    // Leer los datos de la tabla y almacenarlos en la matriz
    // Se asume que los datos están separados por comas y que no hay espacios
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            // Leer el dato como un entero
            fscanf(archivoEntrada, "%d", &datos[i][j]);

            // Si no es la última columna, leer la coma que sigue
            if (j < COLUMNAS - 1) {
                fscanf(archivoEntrada, ",");
            }
        }
        fscanf(archivoEntrada, "\n");  // Leer el salto de línea al final de cada fila
    }

    // Cerrar el archivo de entrada
    fclose(archivoEntrada);

    // Recorrer el rango de filas especificado y sumar los datos de cada columna
    for (int i = INICIO; i <= FIN; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            sumas[j] += datos[i][j];
        }
    }

    // Escribir las sumas de cada columna en el archivo de salida
    // Se separan las sumas por comas y se termina con un salto de línea
    for (int i = 0; i < COLUMNAS; i++) {
        fprintf(archivoSalida, "%d", sumas[i]);

        // Si no es la última columna, escribir una coma
        if (i < COLUMNAS - 1) {
            fprintf(archivoSalida, ",");
        }
    }

    // Escribir un salto de línea al final
    fprintf(archivoSalida, "\n");

    // Cerrar el archivo de salida
    fclose(archivoSalida);

    // Terminar el programa con éxito
    return 0;
}


