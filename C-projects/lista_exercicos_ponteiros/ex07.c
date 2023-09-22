// Ex 07)

#include <stdio.h>


void calcularSoma(float *a, float b) {
    *a = *a + b;
}

int main() {
    float numA, numB;

    printf("Digite o valor de A: ");
    scanf("%f", &numA);

    printf("Digite o valor de B: ");
    scanf("%f", &numB);

    calcularSoma(&numA, numB);

    printf("A apos a soma: %f\n", numA);
    printf("B: %f\n", numB);

    return 0;
}
