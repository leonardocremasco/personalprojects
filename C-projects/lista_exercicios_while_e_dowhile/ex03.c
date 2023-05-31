// ex.3

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_VALUES 100

// Criando o algoritmo para ordenação
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    char string[1000];
    int values[MAX_VALUES];
    int numValues = 0;
    char *token;

    printf("Digite varios numeros inteiros separados por espacos: ");
    fgets(string, sizeof(string), stdin);

    // Quebrando a string em tokens (números inteiros separados por espaços)
    token = strtok(string, " ");
    while (token != NULL && numValues < MAX_VALUES) {
        values[numValues] = atoi(token);
        numValues++;
        token = strtok(NULL, " ");
    }

    // Ordenando os valores em ordem crescente
    bubbleSort(values, numValues);

    printf("Valores ordenados em ordem crescente:\n");
    for (int i = 0; i < numValues; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");

    return 0;
}
