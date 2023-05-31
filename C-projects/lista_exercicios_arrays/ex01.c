// ex.1

#include <stdio.h>

int main() {
    int lista[5] = {3, 5, 7, 4, 1};
    int soma = 0;

    for (int i = 0; i < 5; i++) {
        soma += lista[i];
    }

    printf("A soma dos elementos da lista é: %d\n", soma);

    return 0;
}
