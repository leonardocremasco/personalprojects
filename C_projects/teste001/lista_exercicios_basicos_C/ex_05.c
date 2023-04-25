// Exercício 5 -> Faça um programa que calcule o ano de nascimento de uma pessoa a partir de sua idade e do ano atual

#include <stdio.h>
#include <limits.h>

int main ()
{
    int idade;
    int ano_atual;
    int ano_nasc;

    printf("Qual a sua idade? ");
    scanf("%d%*c", &idade);

    printf("Em que ano estamos? ");
    scanf("%d%*c", &ano_atual);

    // calculando a idade

    ano_nasc = ano_atual - idade;

    printf("\n Considerando sua idade (%d) e o ano em que estamos (%d), voce nasceu em (%d)", idade, ano_atual, ano_nasc);
    return 0;    
}