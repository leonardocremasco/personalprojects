
#ifndef SOMA_H_INCLUDED
#define SOMA_H_INCLUDED
#include <stdio.h>

void soma (){
    int a, b, s;

    printf("\nDigite um numero inteiro: ");
    scanf("%d", &a);
    printf("\nDigite outro numero inteiro: ");
    scanf("%d", &b);
    
    s= a + b;

    printf("\nSoma; %d", s);
}


#endif //soma included