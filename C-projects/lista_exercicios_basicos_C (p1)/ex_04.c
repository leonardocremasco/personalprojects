// Exercício 4 -> Faça um programa que leia 4 valores tipo flaot e calcule a média aritmética desses valores

#include <stdio.h>
#include <limits.h>

int main ()
{
    float lf_1_valor;
    float lf_2_valor;
    float lf_3_valor;
    float lf_4_valor;
    float lf_media;

    printf("Informe um primeiro valor: ");
    scanf("%f%*c", &lf_1_valor);

    printf("Informe um segundo valor: ");
    scanf("%f%*c", &lf_2_valor);

    printf("Informe um terceiro valor: ");
    scanf("%f%*c", &lf_3_valor);

    printf("Informe um quarto valor: ");
    scanf("%f%*c", &lf_4_valor);

    // calculando a media entre esses valores

    lf_media = (lf_1_valor + lf_2_valor + lf_3_valor + lf_4_valor) / 4;

    printf("\n A media aritmetica entre os valoreas (%f + %f + %f + %f) eh: %f", lf_1_valor, lf_2_valor, lf_3_valor, lf_4_valor, lf_media);
    return 0;
}