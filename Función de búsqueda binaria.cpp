/*Función de búsqueda binaria*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int busquedaBinaria(int lista[], int numElementos, int elemento) {
    int primero = 0;
    int ultimo = numElementos - 1;
    int mitad;
    
    while (primero <= ultimo) {
        mitad = (primero + ultimo) / 2;
        
        if (lista[mitad] < elemento) {
            primero = mitad + 1;
        } else if (lista[mitad] == elemento) {
            return mitad;  // Devuelve la posición si encuentra el elemento
        } else {
            ultimo = mitad - 1;
        }
    }
    
    return -1;  // Devuelve -1 si el elemento no se encuentra
}

int main() {
    int i, num, elemento, posicion;
    
    srand(time(NULL));
    int lista[10] = {1, 2, 4, 6, 9, 10, 11, 15, 18, 20};
    num = 10;
    
    printf("Elementos de la lista:\n");
    
    for (i = 0; i < num; i++) {
        printf("%d, ", lista[i]);
    }
    
    printf("\n");
    printf("Elemento a buscar: ");
    scanf("%d", &elemento);
    
    // Llamada a la función de búsqueda binaria
    posicion = busquedaBinaria(lista, num, elemento);
    
    if (posicion != -1) {
        printf("Posicion:%d\n", posicion);
    } else {
        printf("Elemento no se encuentra\n");
    }
    
    return 0;
}

