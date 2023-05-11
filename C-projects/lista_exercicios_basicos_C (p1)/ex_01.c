// Exercício 1 -> Faça um programa que leia um número inteiro e retorne seu antecessor e seu sucessor

#include <stdio.h>
#include <limits.h>

int main ()
{
    int li_numero;
    int li_antecessor;
    int li_sucessor;

    printf("Informe um numero inteiro: ");
    scanf("%d%*c", &li_numero);
    printf("\n O numero digitado foi: %d", li_numero);

    // calculando o antecessor do número digitado

    li_antecessor = li_numero;
    li_antecessor--;

    printf("|n O antecessor eh: %d", li_antecessor);

    // calculando o sucessor do numero digitado

    li_sucessor = li_numero;
    li_sucessor++;

    printf("\n O sucessor eh: %d", li_sucessor);

    return 0;
}