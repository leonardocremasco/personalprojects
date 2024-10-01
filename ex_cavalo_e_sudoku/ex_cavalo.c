
#include <stdio.h>

#define N 8  // Tamanho do tabuleiro (8x8 no caso de um tabuleiro de xadrez)

//todos os mov  possiveis do cavalo
int movX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int movY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

//func para imprimir a solução
void imprime_solucao(int tabuleiro[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            printf(" %2d ", tabuleiro[x][y]);
        printf("\n");
    }
}

// verificacao do movimento
int valido_mov(int x, int y, int tabuleiro[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && tabuleiro[x][y] == -1);
}

// aqui implementa o backtracking com recursão
int solve_passeio(int x, int y, int movNum, int tabuleiro[N][N]) {
    int proxX, proxY;

    // caso todos os quadrados do tabuleiro foram visitados, retorna "sucesso"
    if (movNum == N * N)
        return 1;

    // Tenta todos os movimentos possíveis do cavalo a partir da posição atual
    for (int i = 0; i < 8; i++) {
        proxX = x + movX[i];
        proxY = y + movY[i];

        if (valido_mov(proxX, proxY, tabuleiro)) {
            tabuleiro[proxX][proxY] = movNum;  // Marca o quadrado como visitado

            // usa recursao para chamar a próxima posição
            if (solve_passeio(proxX, proxY, movNum + 1, tabuleiro) == 1)
                return 1;
            else
                tabuleiro[proxX][proxY] = -1;  // Backtracking: desfaz a marcação
        }
    }

    return 0;
}

// Inicializa o tabuleiro e inicia o algoritmo de backtracking
int start_passeio() {
    int tabuleiro[N][N];

    // Inicializa todos os quadrados do tabuleiro como não visitados
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            tabuleiro[x][y] = -1;

    // O cavalo começa na posição inicial (0, 0)
    tabuleiro[0][0] = 0;

    // Chama a função recursiva para resolver o passeio
    if (solve_passeio(0, 0, 1, tabuleiro) == 0) {
        printf("Solução não encontrada\n");
        return 0;
    } else
        imprime_solucao(tabuleiro);

    return 1;
}

int main() {
    start_passeio();
    return 0;
}
