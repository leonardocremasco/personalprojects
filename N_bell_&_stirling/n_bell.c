#include <stdio.h>

// Função para calcular o número de Bell usando o Triângulo de Bell
int bellNumber(int n) {
    int bell[n+1][n+1];

    // Inicializando o primeiro valor do Triângulo de Bell
    bell[0][0] = 1;

    // Preenchendo o Triângulo de Bell
    for (int i = 1; i <= n; i++) {
        // O primeiro valor de cada linha é o último valor da linha anterior
        bell[i][0] = bell[i-1][i-1];

        // Preenchendo os outros valores da linha
        for (int j = 1; j <= i; j++) {
            bell[i][j] = bell[i-1][j-1] + bell[i][j-1];
        }
    }

    // O número de Bell é o primeiro valor da última linha, sempre
    return bell[n][0];
}

int main() {
    int n;

    printf("Entre com um valor para calcular o numero de Bell: ");
    scanf("%d", &n);

    printf("O numero de Bell para %d é %d\n", n, bellNumber(n));

    return 0;
}
