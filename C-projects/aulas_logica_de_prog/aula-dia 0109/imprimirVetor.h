
#ifndef IMPRIMIRVETOR_H_INCLUDED
#define IMPRIMIRVETOR_H_INCLUDED

#include <stdio.h>
#include <math.h>

void imprimirVetor(int vetor[], int tamanho) {
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

#endif