// Arrayz and Matrizes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    int la_numeros[] = {1,4,3,7,100,50, 60};
    int li_i;
    #define TAMANHO_TABELA 7

    // printf("\nla_numeros %d", la_numeros[0]);
    // printf("\nla_numeros %d", la_numeros[1]);
    // printf("\nla_numeros %d", la_numeros[2]);
    // printf("\nla_numeros %d", la_numeros[3]);
    // printf("\nla_numeros %d", la_numeros[4]);
    // printf("\nla_numeros %d", la_numeros[5]);

    // printf("\nstrlen(nla_numeros) = %d", strlen(la_numeros));
    // printf("\nsizeof(nla_numeros) = %d", sizeof(la_numeros));
    // printf("\nsizeof(nla_numeros[0]) = %d", sizeof(la_numeros[0]));    
    // printf("\ntamanho da tabela = %d", sizeof(la_numeros) / sizeof(la_numeros[0]));    

    for (li_i = 0; li_i < TAMANHO_TABELA; li_i++)
    {
        printf("\nla_numeros [%d] = %d",li_i, la_numeros[li_i]);
    }
    

    return 0;
}