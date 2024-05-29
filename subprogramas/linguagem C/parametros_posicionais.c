
// Definição de parâmetros posicionais

#include <stdio.h>
#include <stdlib.h>

int subtracaoSimples (int n1, int n2)
{
    return n1-n2;
}

int main () 
{
    int sub;
    sub = subtracaoSimples(10,8);

    printf("o resultado da subtracao eh: %d", sub);
    return 0;

}