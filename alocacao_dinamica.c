#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3;

    // Alocando espaço para um array de ponteiros
    char **array = malloc(n * sizeof(char *));

    // Alocando espaço para cada string
    array[0] = malloc(6 * sizeof(char));
    array[1] = malloc(6 * sizeof(char));
    array[2] = malloc(6 * sizeof(char));

    // Inicializando as strings
    sprintf(array[0], "Hello");
    sprintf(array[1], "World");
    sprintf(array[2], "C");

    // Imprimindo as strings
    for (int i = 0; i < n; i++) {
        printf("String %d: %s\n", i, array[i]);
        free(array[i]); // Liberando cada string
    }

    free(array); // Liberando o array de ponteiros

    return 0;
}
