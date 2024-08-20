#include <stdio.h>

#define NUM_DENOMINACOES 5

// função para calcular o troco considerando a solução ‘ótima parcial’
int calcularTrocoOtimoParcial(int n, int C[], int qtd_moedas[], int S[]) {
    int s = 0; // valor acumulado do troco
    int i; // indice para iteração dos trocos

    // Inicializando o array S (quantidade de moedas usadas para o troco)
    for (i = 0; i < NUM_DENOMINACOES; i++) {
        S[i] = 0;
    }

    // percorrer enquanto não  alcançar o valor desejado ou não houver mais opções
    while (s < n) {
        int x = -1;

        // aqui é para encontrar a maior moeda que pode ser usada e que ainda está disponível
        for (i = 0; i < NUM_DENOMINACOES; i++) {
            if (C[i] <= n - s && qtd_moedas[i] > 0) {
                x = i;
                break;
            }
        }

        // Se não foi encontrada uma moeda válida, retorne a solução parcial
        if (x == -1) {
            break;
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

    int valor = 103; // Valor do troco desejado

    int troco = calcularTrocoOtimoParcial(valor, C, qtd_moedas, S);

    if (troco == valor) {
        printf("Troco completo encontrado!\n");
    } else {
        printf("Troco parcial encontrado: %d\n", troco);
    }
    
    printf("Moedas utilizadas:\n");
    for (int i = 0; i < NUM_DENOMINACOES; i++) {
        if (S[i] > 0) {
            printf("%d moedas de %d centavos\n", S[i], C[i]);
        }
    }

    return 0;
}