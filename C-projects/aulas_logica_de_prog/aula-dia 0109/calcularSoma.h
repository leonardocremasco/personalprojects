
#ifndef CALCULARSOMA_H_INCLUDED
#define CALCULARSOMA_H_INCLUDED

#include <stdio.h>
#include <math.h>

int calcularSoma(int vetor[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return soma;
}

#endif