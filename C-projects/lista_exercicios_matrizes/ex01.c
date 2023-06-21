//  ex.1 

#include <stdio.h>

int main() {
    int matriz[3][3];
    int i, j;
    int somaHorizontal = 0, somaVertical = 0, somaCrescente = 0, somaDecrescente = 0;

    // Leitura da matriz
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Cálculo da soma dos elementos na horizontal
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            somaHorizontal += matriz[i][j];
        }
    }

    // Cálculo da soma dos elementos na vertical
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 3; i++) {
            somaVertical += matriz[i][j];
        }
    }

    // Cálculo da soma dos elementos na diagonal crescente
    for (i = 0; i < 3; i++) {
        somaCrescente += matriz[i][i];
    }

    // Cálculo da soma dos elementos na diagonal decrescente
    for (i = 0, j = 2; i < 3; i++, j--) {
        somaDecrescente += matriz[i][j];
    }

    // Exibição dos resultados
    printf("Soma dos elementos na horizontal: %d\n", somaHorizontal);
    printf("Soma dos elementos na vertical: %d\n", somaVertical);
    printf("Soma dos elementos na diagonal crescente: %d\n", somaCrescente);
    printf("Soma dos elementos na diagonal decrescente: %d\n", somaDecrescente);

    return 0;
}
