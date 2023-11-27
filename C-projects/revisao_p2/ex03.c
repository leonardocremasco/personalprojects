//Ex03) operações com matriz

#include <stdio.h>
#include <stdlib.h>

void montarMatriz(int *matriz,int linhas, int colunas){

    printf("Digite os elementos da matriz: ");
    for(int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", matriz + i * colunas + j);
        }
    }
}

void mostrarMatriz(int *matriz, int linhas, int colunas){
    printf("Matriz:\n ");
    for(int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%d\t", *(matriz + i * colunas + j));
        }
        printf("\n");
    }
}

void matrizTransposta (int *matriz, int linhas, int colunas, int *transposta){

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            *(transposta + j * linhas + i) = *(matriz + i * colunas + j);
        }
    }
}

int main () {

    int linhas, colunas;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &colunas);

    // função pra alocar a memória pra matriz M
    int *matrizM = (int *)malloc(linhas * colunas * sizeof(int));

    montarMatriz(matrizM, linhas, colunas);
    mostrarMatriz(matrizM, linhas, colunas);

    int *matrizN = (int *)malloc(linhas * colunas * sizeof(int));

    matrizTransposta(matrizM, linhas, colunas, matrizN);
    mostrarMatriz(matrizN, linhas, colunas);

    // função pra liberar o espaço alocado
    free(matrizM);
    free(matrizN);

    return 0;
}