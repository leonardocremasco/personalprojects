
#include <stdio.h>
#define VECTOR_SIZE 10

int main() {
    
    int vector[VECTOR_SIZE];
    int sum = 0;
    int high, low;
    float media;

    // running the matrix and your status
    printf("Digite os %d elementos do vetor\n", VECTOR_SIZE);
    for (int i = 0; i < VECTOR_SIZE; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vector[i]);
        sum += vector[i];
    }

    // average calc.
    media = (float)sum / VECTOR_SIZE;

    // find the highest and the lowest value
    high = low = vector[0];
    for (int i = 1; i < VECTOR_SIZE; i++) {
        if (vector[i] > high) {
            high = vector[i];
        }
        if (vector[i] < low) {
            low = vector[i];
        }
    }

    // Contagem de elementos maiores ou iguais à média
    int quantityHigherOrEqualAverage = 0;
    for (int i = 0; i < VECTOR_SIZE; i++) {
        if (vector[i] >= media) {
            quantityHigherOrEqualAverage++;
        }
    }

    // Exibição dos resultados
    printf("\nO maior elemento do vetor: %d\n", high);
    printf("O menor elemento do vetor: %d\n", low);
    printf("A quantidade de elementos maiores ou iguais a %.2f (média): %d\n", media, quantityHigherOrEqualAverage);

    return 0;
}

    
