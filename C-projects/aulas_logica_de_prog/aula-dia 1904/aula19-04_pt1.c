// Aula duia 19-04-2023 //

#include <stdio.h>
#include <limits.h>
#include <math.h>

int multiplicacao (int p1, int p2)
{
    int produto;
    produto = p1 * p2;
    return produto;
}

int main ()
{
    int resultado;
    resultado = multiplicacao (6,7);
    printf("6 vezes 7 eh %d", resultado);
    return 0;
}