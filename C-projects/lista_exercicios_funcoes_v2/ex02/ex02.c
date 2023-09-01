// Ex02) Verificação se o número é primo

#include <stdio.h>
#include <math.h>
#include "PrimoOuNao.h"

int main() {
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    if (PrimoOuNao(num)) {
        printf("%d EH um numero primo.\n", num);
    } else {
        printf("%d NAO EH um numero primo.\n", num);
    }

    return 0;
}
