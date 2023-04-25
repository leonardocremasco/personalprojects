// Exercício 3 -> Faça um programa que leia a três valores inteiros e mostre sua soma

#include <stdio.h>
#include <limits.h>

int main ()
{
    int li_1_numero;
    int li_2_numero;
    int li_3_numero;
    int li_soma;

    printf("Informe um numero inteiro: ");
    scanf("%d%*c", &li_1_numero);

    printf("Informe um outro numero inteiro: ");
    scanf("%d%*c", &li_2_numero);

    printf("Informe um ultimo numero inteiro: ");
    scanf("%d%*c", &li_3_numero);

    // calculando a soma entre eles

    li_soma = li_1_numero + li_2_numero + li_3_numero;

    printf("\n A soma entre os numeros digitados: (%d + %d + %d) eh = %d", li_1_numero, li_2_numero ,li_3_numero, li_soma);
    return 0;
}