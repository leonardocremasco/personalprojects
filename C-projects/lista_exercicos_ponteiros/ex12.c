// Ex 12)

#include <stdio.h>
#include <stdlib.h>

int ordenarEVerificar(int *a, int *b, int *c) {
    int temp;
    int igual = 0;

    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }

    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }

    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }

    if (*a == *b && *b == *c) {
        igual = 1;
    }

    return igual;
}

int main() {
    int num1, num2, num3;

    printf("Digite tres valores inteiros: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int iguais = ordenarEVerificar(&num1, &num2, &num3);

    printf("Valores ordenados: %d %d %d\n", num1, num2, num3);

    if (iguais) {
        printf("Os tres valores sao iguais.\n");
    } else {
        printf("Os tres valores sao diferentes.\n");
    }

    return 0;
}

