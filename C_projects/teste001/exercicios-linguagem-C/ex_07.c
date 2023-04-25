// Exercício 7 -> Conversão de real em dolar

#include <stdio.h>
#include <limits.h>

int main ()
{
    float valor_reais;
    float cotacao_dolar;
    float valor_convertido;

    printf("Digite um valor em reais: R$ ");
    scanf("%f%*c", &valor_reais);

    printf("Digite a cotacao do dolar hoje: US$ ");
    scanf("%f%*c", &cotacao_dolar);

    // convertendo real em dolar

    valor_convertido = valor_reais / cotacao_dolar;

    printf("\n O valor de R$%f corresponde a US$%f ", valor_reais, valor_convertido);
    return 0;

}