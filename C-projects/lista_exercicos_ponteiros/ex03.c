// Ex 03)

#include <stdio.h>

int main () {

    int valor1, valor2;

    printf("Digite o primeiro valor: ");
    scanf("%d", &valor1);

    printf("Digite o segundo valor: ");
    scanf("%d", &valor2);
    
    int *ptrV1 = &valor1;
    int *ptrV2 = &valor2;

    if (ptrV1 > ptrV2) {
        printf("O maior endereco eh: %p\n", (void *)ptrV1);
    } else if (ptrV2 > ptrV1) {
        printf("O maior endereco eh: %p\n", (void *)ptrV2);
    } else {
        printf("Os enderecos sao iguais: %p\n", (void *)ptrV1);
    }

    return 0;
}

