// Nome: Leonardo Cremasco Bernardes Boscariol
// RA: 202310228
// Curso: Engenharia de Computação

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função de troca
void swap(void *a, void *b, size_t size) {
    void *temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

// Função de comparação para inteiros
int compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Função de comparação para caracteres
int compare_char(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

// Função de partição para o QuickSort
int partition(void *array, int low, int high, size_t size, int (*compare)(const void *, const void *)) {
    char *arr = array;
    void *pivot = arr + high * size;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(arr + j * size, pivot) < 0) {
            i++;
            swap(arr + i * size, arr + j * size, size);
        }
    }
    swap(arr + (i + 1) * size, arr + high * size, size);
    return i + 1;
}

// Função QuickSort genérica
void quicksort(void *array, int low, int high, size_t size, int (*compare)(const void *, const void *)) {
    if (low < high) {
        int pi = partition(array, low, high, size, compare);
        quicksort(array, low, pi - 1, size, compare);
        quicksort(array, pi + 1, high, size, compare);
    }
}

// Função para imprimir o vetor de inteiros
void print_array_int(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Função para imprimir o vetor de caracteres
void print_array_char(char *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", array[i]);
    }
    printf("\n");
}

int main() {
    int choice, n;

    printf("Escolha o tipo de vetor a ser ordenado:\n1 - Inteiros\n2 - Caracteres\n");
    scanf("%d", &choice);

    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    if (choice == 1) {
        int *array = (int *)malloc(n * sizeof(int));
        printf("Digite os elementos inteiros:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &array[i]);
        }

        quicksort(array, 0, n - 1, sizeof(int), compare_int);

        printf("Vetor ordenado: ");
        print_array_int(array, n);
        free(array);
    } else if (choice == 2) {
        char *array = (char *)malloc(n * sizeof(char));
        printf("Digite os elementos caracteres:\n");
        for (int i = 0; i < n; i++) {
            scanf(" %c", &array[i]);
        }

        quicksort(array, 0, n - 1, sizeof(char), compare_char);

        printf("Vetor ordenado: ");
        print_array_char(array, n);
        free(array);
    } else {
        printf("Escolha inválida!\n");
    }

    return 0;
}

/*
Aplicação do QuickSort: O algoritmo QuickSort é selecionado devido à sua complexidade média de tempo reduzida. 
O (n log n), que é eficaz na maioria das situações. Em relação a outros algoritmos de ordenação, como o Bubble Sort O(n2), ele se sobressai pela sua rapidez em entradas de grande dimensão.

Função genérica de ordenação: A utilização de ponteiros genéricos (void *) e funções comparativas torna o código adaptável para ordenar diversos tipos de dados (inteiros e caracteres) sem a exigência de redundância de código. Isso diminui o volume de código e aprimora a sua reutilização.

Troca eficaz: A função swap() só faz uso de alocação dinâmica uma vez por troca, o que é crucial para possibilitar a adaptabilidade a diversos tipos de dados. Embora a alocação dinâmica seja uma característica, ainda assim, ela é dinâmica.
*/