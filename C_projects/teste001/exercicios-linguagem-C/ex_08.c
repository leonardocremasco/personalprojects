//  Exercício 8 -> Conversão de temepraturas [Celsius to Fahrenheit]

#include <stdio.h>
#include <limits.h>

int main ()
{
    int temp_celsius;
    int temp_fahrenheit;
    int conversao_cf;

    printf("Digite uma temperatura em graus Celsius: ");
    scanf("%d%*c", &temp_celsius);

    // conversão de celsius para fahrenheit

    conversao_cf = temp_celsius * (9.0/5.0) + 32;
    temp_fahrenheit = conversao_cf;

    printf("\n A temperatura de %d graus Celsius sera, convertida, %d graus Fahreinheit", temp_celsius, temp_fahrenheit);
    return 0;
}