
#include <stdio.h>

int main() {
    int vetor[8];
    int x, y;

    
    printf("Digite os valores do vetor de 8 posições:\n");
    for (int i = 0; i < 8; i++) {
        printf("Posição %d: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("\nDigite os valores de X e Y (posições do vetor): ");
    scanf("%d %d", &x, &y);

    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        int soma = vetor[x] + vetor[y];
        printf("\nA soma dos valores nas posicoes %d e %d é: %d\n", x, y, soma);
    } else {
        printf("\nAs posições informadas são inválidas!\n");
    }

    return 0;
}
