// ex.5

#include <stdio.h>
#include <ctype.h>

int main() {
    int numeros[5] = {3, 5, 7, 4, 1};
    int i, soma = 0;

    printf("Lista de numeros em ordem invertida:\n");
    for (i = 4; i >= 0; i--) {
        printf("%d ", numeros[i]);
        soma += numeros[i];
    }

    printf("\nSoma dos numeros: %d\n", soma);

    return 0;
}
