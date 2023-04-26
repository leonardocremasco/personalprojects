//  Exercício 9 -> Conversão de medidas [Graus para Radianos]

#include <stdio.h>
#include <limits.h>

int main ()
{
    float angulo_grau;
    float conversao_gr;
    float angulo_rad;
    float pi = 3.141592;

    printf("Digite um angulo em graus: ");
    scanf("%f%*c", &angulo_grau);

    // conversão de graus pra radianos

    conversao_gr = angulo_grau * (pi / 180);
    angulo_rad = conversao_gr;

    printf("\n O angulo de %f graus, em radianos, eh igual a %f rad", angulo_grau, angulo_rad);
    return 0;
}