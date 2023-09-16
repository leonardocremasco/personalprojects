// Ex 14)
#include <stdio.h>

void preencherArray(int *array, int tamanho, int valor) {
    int *ptr = array; 
    int *end = array + tamanho; 

   
    while (ptr < end) {
        *ptr = valor; 
         ptr++; 
}

int main() {
    int meuArray[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(meuArray) / sizeof(meuArray[0]);
    int novoValor = 42;

    printf("Array original: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", meuArray[i]);
    }
    printf("\n");

    preencherArray(meuArray, tamanho, novoValor);

    printf("Array modificado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", meuArray[i]);
    }
    printf("\n");

    return 0;
}
