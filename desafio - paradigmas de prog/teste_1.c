
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int a, b;
    int media;

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Digite o valor de B: ");
    scanf("%d", &b);

    media = (a + b) / 2;

    if (media >= 5){
        printf("Aprovado");
    } else {
        printf("Reprovado");
    }

    return 0;

}