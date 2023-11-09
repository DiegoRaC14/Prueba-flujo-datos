#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    int number;
    int count = 0;

    // Open the CSV file for reading
    inputFile = fopen("emails.csv", "r");
    if (inputFile == NULL) {
        perror("Error opening the input file");
        return 1;
    }

    // Open the output file for writing
    outputFile = fopen("valores.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening the output file");
        fclose(inputFile);
        return 1;
    }

    // Read numbers from the CSV file and count them
    while (fscanf(inputFile, "%d", &number) == 1) {
        fprintf(outputFile, "%d\n", number);
        count++;
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    // Print the count
    printf("Total numbers: %d\n", count);

    return 0;
}


