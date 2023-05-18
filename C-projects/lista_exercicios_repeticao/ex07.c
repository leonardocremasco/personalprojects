

#include <stdio.h>

int main() {
    float soma = 0;
    int i;

    for (i = 1; i <= 50; i++) {
        soma += (float)(2 * i - 1) / i;
    }

    printf("A soma da série é: %.2f", soma);

    return 0;
}
