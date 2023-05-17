// Ex. 8: ler um número e verificar se o mesmo é par ou ímpar

#include <stdio.h>
#include <stdbool.h>

int main () {

    int n1;

    printf("Digite um numero, e verificarei se o mesmo eh PAR ou IMPAR : ");
    scanf("%d", &n1);

    if (n1 % 2 == 0)
    {
        printf("O numero digitado eh PAR.");
    } else {
        printf("O numero digitado eh IMPAR.");
    }

    return 0;
}