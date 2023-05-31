// ex. 4

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
    int i, novaPosicao;

    // Chama a função para ordenar a lista
    ordenarLista(lista, tamanho);

    // Encontra a nova posição do valor 3
    for (i = 0; i < tamanho; i++) {
        if (lista[i] == 3) {
            novaPosicao = i;
            break;
        }
    }

    // Apresenta a lista ordenada e a nova posição do valor 3
    printf("Lista em ordem crescente: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\nNova posicao do valor 3: %d\n", novaPosicao + 1);

    return 0;
}

   
