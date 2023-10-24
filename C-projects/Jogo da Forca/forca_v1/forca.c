// Alunos: Leonardo Cremasco & Vitor Jensen
//Curso: Engenharia de Computação - 2º semestre NOTURNO
//Jogo da Forca

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TENTATIVAS 6
#define NUM_PALAVRAS 5

char *palavras[NUM_PALAVRAS] = {
    "PROGRAMACAO",
    "COMPUTADOR",
    "LINGUAGEM",
    "DESENVOLVIMENTO",
    "OPENAI"
};
void exibirPalavra(char palavra[], int letrasCorretas[]) {
    int i;
    int tam = strlen(palavra);
    for (i = 0; i < tam; i++) {
        if (letrasCorretas[i]) {
            printf("%c ", palavra[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    char *palavraSecreta = palavras[rand() % NUM_PALAVRAS];
    int tamPalavra = strlen(palavraSecreta);
    int letrasCorretas[tamPalavra];
    int tentativas = 0;
    int acertou = 0;

    
    for (int i = 0; i < tamPalavra; i++) {
        letrasCorretas[i] = 0;
    }

    printf("Bem-vindo ao jogo da Forca!\n");

    while (tentativas < MAX_TENTATIVAS) {
        char palpite;
        printf("\nPalavra atual: ");
        exibirPalavra(palavraSecreta, letrasCorretas);
        printf("Digite uma letra: ");
        scanf(" %c", &palpite);

        int letraCorreta = 0;
        for (int i = 0; i < tamPalavra; i++) {
            if (palavraSecreta[i] == palpite) {
                letrasCorretas[i] = 1;
                letraCorreta = 1;
            }
        }

        if (letraCorreta) {
            printf("Letra correta!\n");
        } else {
            printf("Letra incorreta. Tente novamente.\n");
            tentativas++;
        }

        // Verificar se o jogador acertou a palavra
        acertou = 1;
        for (int i = 0; i < tamPalavra; i++) {
            if (!letrasCorretas[i]) {
                acertou = 0;
                break;
            }
        }

        if (acertou) {
            printf("\nParabéns! Você acertou a palavra: %s\n", palavraSecreta);
            break;
        }

        printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
    }

    if (!acertou) {
        printf("\nFim de jogo. A palavra correta era: %s\n", palavraSecreta);
    }

    return 0;
}
