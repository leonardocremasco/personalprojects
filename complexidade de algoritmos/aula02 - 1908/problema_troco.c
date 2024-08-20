#include <stdio.h>

#define NUM_DENOMINACOES 5

// função para calcular o troco considerando uma quantidade limitada de moedas
int calcularTroco(int n, int C[], int qtd_moedas[], int S[]) {
    int s = 0; // Valor acumulado do troco
    int i; // Índice para iteração

    // inicializando o array ‘S’ (qtd de moedas usadas para o troco)
    for (i = 0; i < NUM_DENOMINACOES; i++) {
        S[i] = 0;
    }

    // percorrer enquanto não alcançar o valor desejado ou não houver mais opções
    while (s < n) {
        int x = -1;

        //  para encontrar a maior moeda que pode ser usada e que ainda está disponível
        for (i = 0; i < NUM_DENOMINACOES; i++) {
            if (C[i] <= n - s && qtd_moedas[i] > 0) {
                x = i;
                break;
            }
        }

        // Se não foi encontrada uma moeda válida, interrompa o loop
        if (x == -1) {
            printf("Não foi encontrada uma solução completa.\n");
            return s;
        }

        // Usar a moeda
        S[x]++;
        qtd_moedas[x]--;
        s += C[x];
    }

    return s; // Retorna o valor total de troco calculado
}

int main() {
    int C[NUM_DENOMINACOES] = {100, 25, 10, 5, 1}; // Denominações de moedas
    int qtd_moedas[NUM_DENOMINACOES] = {1, 3, 5, 2, 5}; // Quantidade disponível de cada moeda
    int S[NUM_DENOMINACOES]; // Quantidade de moedas usadas para o troco

    int valor = 63; // Valor do troco desejado

    int troco = calcularTroco(valor, C, qtd_moedas, S);

    printf("Troco calculado: %d\n", troco);
    printf("Moedas utilizadas:\n");
    for (int i = 0; i < NUM_DENOMINACOES; i++) {
        if (S[i] > 0) {
            printf("%d moedas de %d centavos\n", S[i], C[i]);
        }
    }

    return 0;
}           