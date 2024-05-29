
// Definições básicas em subprogramas: cabeçalho, perfil de parâmetro, protocolos, chamada de subprograma

#include <stdio.h>
#include <stdlib.h>

void SomaSimples (int a, int b) // nome(parâmetro formal = void), tipo, parâmetros e tipo de retorno (void não retorna)
{
    printf("o resultado da soma eh: %d", a+b);
}

int main ()
{
    SomaSimples(3,5); // chamada da função (chamada do subprograma)
    return 0;
}