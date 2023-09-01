

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetor(int vetor[], int tamanho);
int encontrarMaiorElemento(int vetor[], int tamanho);
void imprimirVetor(int vetor[], int tamanho);
int calcularSoma(int vetor[], int tamanho);


int main() {
    int vetor[10];

    preencherVetor(vetor, 10);
    imprimirVetor(vetor, 10);

    int maior = encontrarMaiorElemento(vetor, 10);
    printf("Maior elemento: %d\n", maior);

    int soma = calcularSoma(vetor, 10);
    printf("Soma dos elementos: %d\n", soma);

    return 0;
}

// Função com retorno e com argumentos
int calcularSoma(int vetor[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return soma;
}
