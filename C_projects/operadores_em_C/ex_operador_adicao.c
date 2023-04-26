// operador: ADIÇÃO

#include <stdio.h>
#include <limits.h>

int adicao (int p1, int p2)
{
    int produto;
    produto = p1 + p2;
    return produto;
}

int main ()
{
    int primeiro_n;
    int segundo_n;
   
    printf("Digite um numero:");
    scanf("%d%*c", &primeiro_n);

    printf("Digite um outro numero: ");
    scanf("%d%*c", &segundo_n);

    int resultado;
    resultado = adicao(primeiro_n, segundo_n);
    printf("%d mais %d eh %d ", primeiro_n, segundo_n, resultado);
    return 0;
}