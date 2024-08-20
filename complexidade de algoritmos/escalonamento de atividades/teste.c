#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma atividade
typedef struct {
    int inicio;
    int fim;
} Atividade;

// Função de comparação para qsort (ordena atividades por horário de término)
int compararAtividades(const void *a, const void *b) {
    Atividade *atividadeA = (Atividade *)a;
    Atividade *atividadeB = (Atividade *)b;
    return atividadeA->fim - atividadeB->fim;
}

// Função para encontrar o máximo número de atividades que podem ser realizadas
void escalonarAtividades(Atividade atividades[], int n) {
    // Ordena as atividades pelo horário de término
    qsort(atividades, n, sizeof(Atividade), compararAtividades);

    printf("Atividades selecionadas (horario de inicio - horario de termino):\n");

    // Seleciona a primeira atividade
    int ultimaAtividadeSelecionada = 0;
    printf("(%d - %d)\n", atividades[ultimaAtividadeSelecionada].inicio, atividades[ultimaAtividadeSelecionada].fim);

    // Itera sobre as atividades e seleciona aquelas que não se sobrepõem
    for (int i = 1; i < n; i++) {
        if (atividades[i].inicio >= atividades[ultimaAtividadeSelecionada].fim) {
            printf("(%d - %d)\n", atividades[i].inicio, atividades[i].fim);
            ultimaAtividadeSelecionada = i;
        }
    }
}

int main() {
    // Exemplo de atividades com horários de início e fim
    Atividade atividades[] = {{1, 3}, {2, 5}, {4, 6}, {6, 7}, {5, 8}, {8, 9}};
    int n = sizeof(atividades) / sizeof(atividades[0]);

    escalonarAtividades(atividades, n);

    return 0;
}
