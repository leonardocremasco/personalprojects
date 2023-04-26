// operador: IGUALDADE

#include <stdio.h>
#include <limits.h>

int igualdade (int p1, int p2)
{
    int produto;
    produto = (p1 = p2);
    return produto;
}

int main ()
{
    int primeiro_valor;

    printf("Digite um valor inteiro para (x): ");
    scanf("%d%*c", &primeiro_valor);
}

