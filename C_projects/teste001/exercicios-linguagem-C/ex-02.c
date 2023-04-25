// Exercício 2 -> Faça um programa que leia um número real e imprima a quinta parte desse número

#include <stdio.h>
#include <limits.h>

int main()
{
    float lf_numero;
    float lf_quinta_parte;

    printf("Digite um numero real: ");
    scanf("%f%*c", &lf_numero);

    // calculando a quinta parte do numero informado acima

    lf_quinta_parte = lf_numero / 5;

    //  voltando o resultado

    printf("\n A 5a parte do numero digitado anteriormente eh: %f", lf_quinta_parte);
    return 0;
}