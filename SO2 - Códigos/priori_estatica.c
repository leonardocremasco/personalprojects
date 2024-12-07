/* Vitor Niels Flores Jensen. RA: 202310296 */
/* Leonardo Cremasco Bernardes Boscariol. RA: 202310228*/
/* Rafael Fernandes. RA: 202310406*/
/* Jo�o Victor Borduchi Olivatto. RA: 202310162 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10
#define MAX_NAME_LEN 50
#define MAX_PRIORITY 4

// Estrutura para representar um processo
typedef struct {
    int pid;
    char name[50];
    int priority;
    int cpu_cycles;
    int io_cycles;
} Process;

Process process_table[MAX_PROCESSES];
int process_count = 0;
int next_pid = 100;

// Funções auxiliares
void pause() {
    printf("Pressione ENTER para continuar ...");
    getchar();
    getchar();
}

void clear_screen() {
    printf("\033[H\033[J");
}

void incluir_processo() {
    if (process_count >= MAX_PROCESSES) {
        printf("Tabela de processos cheia. Nao eh posssvel adicionar mais processos.\n");
        pause();
        return;
    }

    Process new_process;
    new_process.pid = next_pid++;
    printf("-----------------------------------------------------------\n");
    printf("PID: %d (atribuido automaticamente)\n", new_process.pid);
    printf("NOME: ");
    scanf(" %[^\n]", new_process.name);
    printf("PRIORIDADE (0-4): ");
    scanf("%d", &new_process.priority);
    printf("CPU: ");
    scanf("%d", &new_process.cpu_cycles);
    printf("I/O: ");
    scanf("%d", &new_process.io_cycles);
    printf("-----------------------------------------------------------\n");
    printf("Confirmar a Inclusao desse processo (S/N): ");
    char confirm;
    scanf(" %c", &confirm);
    if (confirm == 'S' || confirm == 's') {
        process_table[process_count++] = new_process;
        printf("Processo incluido com sucesso!\n");
    } else {
        printf("Inclusao cancelada.\n");
    }
    pause();
}

void exibir_processo() {
    int pid;
    int i;
    printf("PID: ");
    scanf("%d", &pid);
    for (i = 0; i < process_count; i++) {
        if (process_table[i].pid == pid) {
            printf("-----------------------------------------------------------\n");
            printf("PID: %d\n", process_table[i].pid);
            printf("NOME: %s\n", process_table[i].name);
            printf("PRIORIDADE: %d\n", process_table[i].priority);
            printf("CPU: %d\n", process_table[i].cpu_cycles);
            printf("I/O: %d\n", process_table[i].io_cycles);
            printf("-----------------------------------------------------------\n");
            pause();
            return;
        }
    }
    printf("Processo nao encontrado.\n");
    pause();
}

void alterar_processo() {
    int pid;
    int i;
    printf("PID: ");
    scanf("%d", &pid);
    for (i = 0; i < process_count; i++) {
        if (process_table[i].pid == pid) {
            printf("-----------------------------------------------------------\n");
            printf("NOME (%s): ", process_table[i].name);
            scanf(" %[^\n]", process_table[i].name);
            printf("PRIORIDADE (%d): ", process_table[i].priority);
            scanf("%d", &process_table[i].priority);
            printf("CPU (%d): ", process_table[i].cpu_cycles);
            scanf("%d", &process_table[i].cpu_cycles);
            printf("I/O (%d): ", process_table[i].io_cycles);
            scanf("%d", &process_table[i].io_cycles);
            printf("-----------------------------------------------------------\n");
            printf("Confirmar a Alteracao (S/N): ");
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'S' || confirm == 's') {
                printf("Processo alterado com sucesso!\n");
            } else {
                printf("Alteracao cancelada.\n");
            }
            pause();
            return;
        }
    }
    printf("Processo nao encontrado.\n");
    pause();
}

void remover_processo() {
    int pid;
    int i,j;
    printf("PID: ");
    scanf("%d", &pid);
    for (i = 0; i < process_count; i++) {
        if (process_table[i].pid == pid) {
            printf("-----------------------------------------------------------\n");
            printf("NOME: %s\n", process_table[i].name);
            printf("PRIORIDADE: %d\n", process_table[i].priority);
            printf("CPU: %d\n", process_table[i].cpu_cycles);
            printf("I/O: %d\n", process_table[i].io_cycles);
            printf("-----------------------------------------------------------\n");
            printf("Confirmar a Remocao (S/N): ");
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'S' || confirm == 's') {
                for (j = i; j < process_count - 1; j++) {
                    process_table[j] = process_table[j + 1];
                }
                process_count--;
                printf("Processo removido com sucesso!\n");
            } else {
                printf("Remocao cancelada.\n");
            }
            pause();
            return;
        }
    }
    printf("Processo nao encontrado.\n");
    pause();
}

void exibir_tabela_processos() {
    int i;
    printf("-----------------------------------------------------------\n");
    printf("NOME    PID    PRI    CPU    I/O\n");
    for (i = 0; i < process_count; i++) {
        printf("%s    %d    %d    %d    %d\n", process_table[i].name, process_table[i].pid,
               process_table[i].priority, process_table[i].cpu_cycles, process_table[i].io_cycles);
    }
    printf("-----------------------------------------------------------\n");
    pause();
}

void remover_todos_processos() {
    printf("Confirmar a Remocao de todos os processos (S/N): ");
    char confirm;
    scanf(" %c", &confirm);
    if (confirm == 'S' || confirm == 's') {
        process_count = 0;
        printf("Todos os processos foram removidos.\n");
    } else {
        printf("Remocao cancelada.\n");
    }
    pause();
}

void executar_algoritmo() {
    int i,j;
    if (process_count == 0) {
        printf("Nenhum processo para executar.\n");
        pause();
        return;
    }

    // Ordenar os processos por prioridade (menor valor -> maior prioridade)
    for (i = 0; i < process_count - 1; i++) {
        for (j = i + 1; j < process_count; j++) {
            if (process_table[i].priority > process_table[j].priority) {
                Process temp = process_table[i];
                process_table[i] = process_table[j];
                process_table[j] = temp;
            }
        }
    }

    printf("-------------------------------------------------------------\n");
    printf("Executando o algoritmo de Prioridade Estatica...\n");
    printf("NOME    PID    PRI    CPU    I/O     TERMINO\n");

    int time_elapsed = 0; // Contador de tempo total

    for (i = 0; i < process_count; i++) {
        Process *current_process = &process_table[i];

        // Simular o tempo necessario para executar o processo
        int execution_time = current_process->cpu_cycles + current_process->io_cycles;
        time_elapsed += execution_time;

        printf("%-8s %-6d %-6d %-6d %-6d %-8d\n",
               current_process->name,
               current_process->pid,
               current_process->priority,
               current_process->cpu_cycles,
               current_process->io_cycles,
               time_elapsed);
    }

    printf("-------------------------------------------------------------\n");
    printf("Todos os processos foram executados.\n");
    pause();
}

void exibir_participantes() {
    printf("-----------------------------------------------------------\n");
    printf("1. Leonardo Cremasco Bernardes Boscariol\n");
    printf("2. Vitor Niels Flores Jensen\n");
    printf("3. Rafael Fernandes\n");
    printf("4. Joao Victor Borduchi Olivatto\n");
    printf("-----------------------------------------------------------\n");
    pause();
}

int main() {
    int opcao;

    do {
        clear_screen();
        printf("Algoritmo de Escalonamento de Processos - Prioridade Estatica \n");
        printf("-----------------------------------------------------------\n");
        printf("1. Incluir Processo\n");
        printf("2. Exibir dados do Processo\n");
        printf("3. Alterar dados do Processo\n");
        printf("4. Remover Processo\n");
        printf("5. Exibir a Tabela de Processos\n");
        
        printf("6. Remover todos os Processos\n");
        printf("7. Executar o Algoritmo\n");
        printf("8. Exibir os Participantes da Equipe\n");
        printf("9. Encerrar a execucao do programa\n");
        printf("-----------------------------------------------------------\n");
        printf("Opcao (1-9): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: incluir_processo(); break;
            case 2: exibir_processo(); break;
            case 3: alterar_processo(); break;
            case 4: remover_processo(); break;
            case 5: exibir_tabela_processos(); break;
            case 6: remover_todos_processos(); break;
            case 7: executar_algoritmo(); break;
            case 8: exibir_participantes(); break;
            case 9: printf("Encerrando o programa...\n"); break;
            default: printf("Opcao invalida. Tente novamente.\n"); pause(); break;
        }
    } while (opcao != 9);

    return 0;
}
