// Ex. 06)

#include <stdio.h>

// Função para retornar a soma do dobro de dois números e modificar os valores de A e B
int somaDoDobro(int *a, int *b) {
    int resultado = (*a * 2) + (*b * 2);
    *a = *a * 2;
    *b = *b * 2;
    return resultado;
}

int main() {
    int numA, numB;

    printf("Digite o valor de A: ");
    scanf("%d", &numA);

    printf("Digite o valor de B: ");
    scanf("%d", &numB);

    int resultado = somaDoDobro(&numA, &numB);

    printf("Soma do dobro de A e B: %d\n", resultado);
    printf("A apos a operação: %d\n", numA);
    printf("B apos a operação: %d\n", numB);

    return 0;
}
