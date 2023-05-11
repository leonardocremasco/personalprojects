// operador: DIVISÃO

#include <stdio.h>
#include <math.h>

int divisao (int p1, int p2)
{
    float produto;
    produto = p1 / p2;
    return produto;
}

int main ()
{
    float primeiro_n;
    float segundo_n;
    float resultado;
   
    printf("Digite um numero:");
    scanf("%f%*c", &primeiro_n);

    printf("Digite um outro numero: ");
    scanf("%f%*c", &segundo_n);

    resultado = divisao(primeiro_n, segundo_n);

    printf("%f dividido por %f eh %f ", primeiro_n, segundo_n, resultado);
    return 0;
}