/************************************************************************************** 
*** Programa que calcula o determinante de uma matriz 3x3 usando a Regra de Sarrus,
*** de forma paralela, com threads.
*** Nome dos componentes da equipe:
*** - Leonardo Cremasco Bernardes Boscariol
*** - Vitor Niels Flores Jensen
**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// struct para armazenar a matriz
typedef struct {
    int matriz[3][3];
    int resultado;
} DadosDiagonais;

// func para calcular a diagon principal
void *calcula_diagonais_principais(void *arg) {
    DadosDiagonais *dados = (DadosDiagonais *)arg;
    dados->resultado = 
            (dados->matriz[0][0] * dados->matriz[1][1] * dados->matriz[2][2]) +
            (dados->matriz[0][1] * dados->matriz[1][2] * dados->matriz[2][0]) +
            (dados->matriz[0][2] * dados->matriz[1][0] * dados->matriz[2][1]);
    pthread_exit(NULL);
}

// func para calcular a diagon secundaria
void *calcula_diagonais_secundarias(void *arg) {
    DadosDiagonais *dados = (DadosDiagonais *)arg;
    dados->resultado = -((dados->matriz[0][2] * dados->matriz[1][1] * dados->matriz[2][0]) +
                         (dados->matriz[0][0] * dados->matriz[1][2] * dados->matriz[2][1]) +
                         (dados->matriz[0][1] * dados->matriz[1][0] * dados->matriz[2][2]));
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    DadosDiagonais dadosPrincipais, dadosSecundarias;
    FILE *arquivo;
    arquivo = fopen("matriz.txt", "r");
    if (arquivo == NULL) {
        printf("--------------------------------------------------\n");
        printf("Nao foi possivel abrir o arquivo matriz.txt\n");
        printf("--------------------------------------------------\n");
        exit(1);
    }

    // preenche a matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fscanf(arquivo, "%d", &dadosPrincipais.matriz[i][j]);
            dadosSecundarias.matriz[i][j] = dadosPrincipais.matriz[i][j];
        }
    }
    fclose(arquivo);

    // criação de threads para
    pthread_create(&thread1, NULL, calcula_diagonais_principais, (void *)&dadosPrincipais);
    pthread_create(&thread2, NULL, calcula_diagonais_secundarias, (void *)&dadosSecundarias);

    // espera as thread terminarem
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // calculo do det pelas diagonais
    int determinante = dadosPrincipais.resultado + dadosSecundarias.resultado;

    // exibir resultado
    printf("--------------------------------------------------\n");
    printf("Diagonais Principais: %d\n", dadosPrincipais.resultado);
    printf("Diagonais Secundarias: %d\n", dadosSecundarias.resultado);
    printf("Determinante: %d\n", determinante);
    printf("--------------------------------------------------\n");

    return 0;
}
