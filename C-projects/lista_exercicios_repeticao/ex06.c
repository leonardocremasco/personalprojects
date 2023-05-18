//  Ex. 6: Xerox

#include <stdio.h>

int main() {
    float numero;
    int i;

    printf("Digite o numero real: ");
    scanf("%f", &numero);

    printf("Valor do Xerox: R$ %.2f\n", numero);
    printf("\n");

    for (i = 1; i <= 200; i++) {
        printf("%d = %.2f \n", i, numero * i);

        if (i % 10 == 0) {
            printf("\n");
        }
    }

    return 0;
}
