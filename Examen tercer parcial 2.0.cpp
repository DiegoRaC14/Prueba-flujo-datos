#include <stdio.h>

int main() 
{
    FILE *archivoEntrada = fopen("emails.csv", "r");
    FILE *archivoSalida = fopen("177195.txt", "w");

    if (archivoEntrada == NULL || archivoSalida == NULL)//Checa si hubo algún error en la apertura de los archivos
	{
        perror("Error al abrir el archivo");//Manda mensaje si existe un error con el archivo
        return 1;
    }

    // Leer y descartar la primera línea con los encabezados
    char buffer[3000];
    fgets(buffer, sizeof(buffer), archivoEntrada);

    // Inicializar variables para las sumas
    int suma_the = 0, suma_to = 0, suma_ect = 0, suma_and = 0, suma_for = 0;

    // Leer y sumar los valores desde "the" del Email 3 al 6
    for (int i = 0; i < 4; i++) 
	{
        fscanf(archivoEntrada, "%*[^,],%*[^,],%d,%d,%d,%d,%d", &suma_the, &suma_to, &suma_ect, &suma_and, &suma_for);
    }

    // Imprimir las sumas en el archivo de salida
    fprintf(archivoSalida, "Suma the: %d\n", suma_the);
    fprintf(archivoSalida, "Suma to: %d\n", suma_to);
    fprintf(archivoSalida, "Suma ect: %d\n", suma_ect);
    fprintf(archivoSalida, "Suma and: %d\n", suma_and);
    fprintf(archivoSalida, "Suma for: %d\n", suma_for);
    
    printf("Suma the: %d\n", suma_the);

    // Cerrar los archivos
    fclose(archivoEntrada);
    fclose(archivoSalida);

    printf("Todo esta viento en popa.\n");

    return 0;
}

