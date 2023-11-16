/*Benchmark búsqueda secuencial*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función de búsqueda secuencial
int busquedaSecuencial(int lista[], int numElementos, int elemento) {
    int bandera = 0;

    for (int i = 0; i < numElementos; i++) {
        if (lista[i] == elemento) {
            printf("Elemento en posicion: %d\n", i + 1);
            bandera = 1;
            break;
        }
    }

    if (bandera == 0) {
        printf("Elemento no se encuentra\n");
    }

    return bandera;
}

int main() {
    int num, elemento;

    srand(time(NULL));
    printf("Numero de elementos a crear: ");
    scanf("%d", &num);

    int lista[num];
    printf("Elemento a buscar: ");
    scanf("%d", &elemento);

    for (int i = 0; i < num; i++) {
        lista[i] = rand() % (10 + 1 - 1) + 1;
    }

    printf("Elementos de la lista\n");

    for (int i = 0; i < num; i++) {
        printf("%d, ", lista[i]);
    }
    printf("\n");

    // Inicio del cronómetro
    clock_t tic = clock();

    // Llamada a la función de búsqueda secuencial
    busquedaSecuencial(lista, num, elemento);

    // Fin del cronómetro
    clock_t toc = clock();

    // Cálculo del tiempo transcurrido
    double tiempo_transcurrido = (double)(toc - tic) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos\n", tiempo_transcurrido);

    return 0;
}

