#ifndef POTENCIA_H_INCLUDED
#define POTENCIA_H_INCLUDED

#include <math.h>
#include <stdio.h>

void potencia(){
    float e, b, potencia;
    printf("\nDigite o valor da base:");
    scanf("%f",&b);
    printf("\nDigite o valor do expoente:");
    scanf("%f",&e);
    potencia = pow(b,e);
    printf("\nPotencia: %0.1f",potencia);
}

#endif // POTENCIA_H_INCLUDED
