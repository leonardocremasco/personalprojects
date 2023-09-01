
#ifndef PAR_H_INCLUDED
#define PAR_H_INCLUDED

#include <stdio.h>
#include <math.h>

int par () {
    int n, z;

    printf("\nDigite um numero inteiro: ");
    scanf("%d", &n);
    z = n & 2;
    
    return z;
}

#endif