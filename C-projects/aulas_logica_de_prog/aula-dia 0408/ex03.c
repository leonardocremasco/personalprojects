
#include <stdio.h>

int main() {
    int vector[10];
    int count_pares = 0;

    printf("Digite os valores do vetor de 10 posicoes:\n");
    for (int i = 0; i < 10; i++) {
        printf("Posição %d: ", i);
        scanf("%d", &vector[i]);
    }

    for (int i = 0; i < 10; i++) {
        if (vector[i] % 2 == 0) {
            count_pares++;
        }
    }

    // Exibição do resultado
    printf("\nO vetor possui %d valor(es) par(es).\n", count_pares);

    return 0;
}
