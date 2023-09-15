
#include <stdio.h>

int main() {
    int vet[] = {45, 67, 12, 89, 34};
    int tamanho = sizeof(vet) / sizeof(vet[0]);
    int *ptr = vet;
    int maior = *ptr; 

    for (int i = 1; i < tamanho; i++) {
        ptr++; 
        if (*ptr > maior) {
            maior = *ptr; 
        }
    }

    printf("O maior valor no vetor é: %d\n", maior);

    return 0;
}
