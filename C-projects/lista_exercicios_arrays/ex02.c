// ex. 2

#include <stdio.h>
#include <ctype.h>

// Função para ordenar a lista em ordem crescente
void ordenarLista(int lista[], int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho-1; i++) {
        for (j = 0; j < tamanho-i-1; j++) {
            if (lista[j] > lista[j+1]) {
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }
}

int main() {
    int lista[5] = {3, 5, 7, 4, 1};
    int tamanho = 5;
    int i, soma = 0;

    // Chama a função para ordenar a lista
    ordenarLista(lista, tamanho);

    // Calcula a soma dos elementos
    for (i = 0; i < tamanho; i++) {
        soma += lista[i];
    }

    // Apresenta a lista ordenada e a soma
    printf("Lista em ordem crescente: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\nSoma dos elementos: %d\n", soma);

    return 0;
}

