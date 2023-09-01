
#ifndef DIVISAO_H_INCLUDED
#define DIVISAO_H_INCLUDED

#include <stdio.h>
#include <math.h>

float divisao(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Erro: divisao por zero nao eh permitida.\n");
        return 0; // Valor padrão para evitar problemas
    }
}
#endif