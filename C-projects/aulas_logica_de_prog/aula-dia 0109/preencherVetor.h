
#ifndef PREENCHERVETOR_H_INCLUDED
#define PREENCHERVETOR_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void preencherVetor(int vetor[], int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100; // Preenche o vetor com números aleatórios de 0 a 99
    }
}

#endif