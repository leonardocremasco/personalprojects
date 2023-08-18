// Ex01) Leia 5 nomes de até 50 caracteres e armazenar em uma matriz de strings. Mostrar os nomes em ordem alfabética 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_NAMES 5
#define MAX_NAME_LENGTH 50

// Função de comparação para qsort
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char names[NUM_NAMES][MAX_NAME_LENGTH + 1];  // +1 for null terminator
    char *sortedNames[NUM_NAMES];

   
    printf("Digite os %d nomes:\n", NUM_NAMES);
    for (int i = 0; i < NUM_NAMES; i++) {
        printf("Nome %d: ", i + 1);
        scanf("%s", names[i]);
        sortedNames[i] = names[i];  // apontando para a matriz originária
    }

    // ordenando os nomes
    qsort(sortedNames, NUM_NAMES, sizeof(char *), compareStrings);

    
    printf("\nNomes em ordem alfabética:\n");
    for (int i = 0; i < NUM_NAMES; i++) {
        printf("%d. %s\n", i + 1, sortedNames[i]);
    }

    return 0;
}
