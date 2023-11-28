//Ex04) Funções com matrizes + multiplicação matricial

#include <stdio.h>
#include <stdlib.h>

//função preencher matriz
void montarMatriz(int **matriz, int linhas, int colunas) {
    
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

//função exibição de matriz
void mostrarMatriz(int **matriz, int linhas, int colunas) {
   
    printf("Matriz:\n");
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

//função de multiplicação de matrizes
void multiMatrizes(int **mA, int **mB, int **mC, int lA, int cA, int cB){

    for(int i = 0; i < lA; i++){
        for (int j = 0; j < cB; i++){
            mC[i][j] = 0; // montando a matriz C a partir do produto de AXB
            for (int k = 0; k < cA; i++){
                mC[i][j] += mA[i][k] * mB[k][j];
            }
        }
    }
}

int main () {

    int lA, cA, lB, cB;

    printf("Digite o numero de linhas da matriz A: ");
    scanf("%d", &lA);
    printf("Digite o numero de colunas da matriz A: ");
    scanf("%d", &cA);

    //alocando memoria e organizando para linha e coluna da matriz
    int **mA = (int **)malloc(lA * sizeof(int *));
    for (int i = 0; i < lA; ++i) {
        mA[i] = (int *)malloc(cA * sizeof(int));
    }

    //chamando função que preenche a matriz
    montarMatriz(mA, lA, cA);

    printf("Digite o numero de linhas da matriz B: ");
    scanf("%d", &lB);
    printf("Digite o numero de colunas da matriz B: ");
    scanf("%d", &cB);

    //alocando memoria e organizando para linha e coluna da matriz
    int **mB = (int **)malloc(lB * sizeof(int *));
    for (int i = 0; i < lA; ++i) {
        mA[i] = (int *)malloc(cA * sizeof(int));
    }

    //chamando a função que preenche a matriz
    montarMatriz(mB, lB, cB);


    // verificação de erro da multiplicação
    if (cA != lB) {
        printf("Nao eh possivel multiplicar as matrizes. O numero de colunas de A deve ser igual ao nmero de linhas de B.\n");
        return 1;
    }

    // alocando memória e organizando as linhas e colunas da matriz C
    int **mC = (int **)malloc(lA * sizeof(int *));
    for (int i = 0; i < lA; ++i) {
        mC[i] = (int *)malloc(cB * sizeof(int));
    }

    // multiplicando matriz A & matriz B, escrevendo resultado na matriz C
    multiMatrizes(mA, mB, mC, lA, cA, cB);

    // exibindo as matrizes A, B e C
    printf("\nMatriz A:\n");
    mostrarMatriz(mA, lA, cA);

    printf("\nMatriz B:\n");
    mostrarMatriz(mB, lB, cB);

    printf("\nMatriz Resultante C:\n");
    mostrarMatriz(mC, lA, cB);

    // liberando as memórias alocadas
    for (int i = 0; i < lA; ++i) {
        free(mA[i]);
    }
    free(mA);

    for (int i = 0; i < lB; ++i) {
        free(mB[i]);
    }
    free(mB);

    for (int i = 0; i < lA; ++i) {
        free(mC[i]);
    }
    free(mC);

    return 0;

}
