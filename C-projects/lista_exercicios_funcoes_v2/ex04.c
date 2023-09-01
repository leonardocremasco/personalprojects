// Ex04) Jogo de advinhação

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// função para gerar um número aleatório entre um min e um max
int GeracaoAleatoria(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    int minRange = 1;
    int maxRange = 100;
    int randomNumber, guess;
    int attempts = 0;

    // inicializa a função para geração de números aleatórios
    srand(time(NULL));

    // gera um número aleatório no intervalo definido (no caso, de 1 a 100)
    randomNumber = GeracaoAleatoria(minRange, maxRange);

    printf("Bem-vindo ao jogo de adivinhacao!\n");
    printf("Tente adivinhar um numero entre %d e %d.\n", minRange, maxRange);

    do {
        printf("Digite o seu palpite: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < randomNumber) {
            printf("Tente um numero maior.\n");
        } else if (guess > randomNumber) {
            printf("Tente um numero menor.\n");
        } else {
            printf("Parabens! Voce acertou o numero %d em %d tentativas.\n", randomNumber, attempts);
        }
    } while (guess != randomNumber);

    return 0;
}
