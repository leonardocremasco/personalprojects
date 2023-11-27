//Ex2) Multiplicação de matrizes

#include <stdio.h>
#include <stdlib.h>

int main() {
    int l1, c1, l2, c2;

    // dados 1 matriz (linha x coluna)
    printf("Digite o numero de linhas da matriz 1: ");
    scanf("%d", &l1);
    printf("Digite o numero de colunas da matriz 1: ");
    scanf("%d", &c1);

    // dados da 2 matriz (linha x coluna)
    printf("\nDigite o numero de linhas da matriz 2: ");
    scanf("%d", &l2);
    printf("Digite o numero de colunas da matriz 2: ");
    scanf("%d", &c2);

    //verificação de erro (nao existe multiplicação)
    if (c1 != l2) {
        printf("\nErro: As matrizes nao podem ser multiplicadas. O numero de colunas da matriz 1 deve ser igual ao numero de linhas da matriz 2.\n");
        return 1; // erro, logo, nao existe multi.
    }

    // montando as matrizes + matriz resultado
    double m1[l1][c1], m2[l2][c2], mR[l1][c2];

    // elementos 1 matriz
    printf("Digite os elementos da matriz 1:\n");
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &m1[i][j]);
        }
    }

    // elementos 2 matriz
    printf("Digite os elementos da matriz 2:\n");
    for (int i = 0; i < l2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &m2[i][j]);
        }
    }

    // produto das matrizes
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            mR[i][j] = 0; // zerada pois vamos formá-la
            for (int k = 0; k < c1; k++) {
                mR[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    // matriz resultante
    printf("\nMatriz Resultante:\n");
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%.2f\t", mR[i][j]);
        }
        printf("\n");
    }

    return 0;
}
