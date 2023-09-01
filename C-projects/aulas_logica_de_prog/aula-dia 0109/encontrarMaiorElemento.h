
#ifndef PREENCHERVETOR_H_INCLUDED
#define PREENCHERVETOR_H_INCLUDED

#include <stdio.h>
#include <math.h>

int encontrarMaiorElemento(int vetor[], int tamanho) {
    int maior = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

#endif