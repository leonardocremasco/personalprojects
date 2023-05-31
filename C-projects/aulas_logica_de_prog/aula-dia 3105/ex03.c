// Arrayz and Matrizes (quando não sei o tamanho do array)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    int la_numeros[] = {1,4,3,7,100,50, 60};
    int la_numeros2[] = {};
    int li_i;
    int li_tamanho_tabela=sizeof(la_numeros) / sizeof(la_numeros[0]);


    for (li_i = 0; li_i < li_tamanho_tabela; li_i++)
    {
        printf("\nla_numeros [%d] = %d",li_i, la_numeros[li_i]);
    }

    li_tamanho_tabela = sizeof(la_numeros2) / sizeof(la_numeros2[0]);

    for (li_i = 0; li_i < li_tamanho_tabela; li_i++)
    {
        printf("\nla_numeros [%d] = %d",li_i, la_numeros[li_i]);
    }    

    return 0;
}