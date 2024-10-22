#include <stdio.h>

#define MAX 10  // Tamanho máximo para o conjunto

// Estrutura para representar um par ordenado
typedef struct {
    int x, y;
} Par;

// Função para imprimir o conjunto
void imprimirConjunto(int A[], int sizeA) {
    printf("{ ");
    for (int i = 0; i < sizeA; i++) {
        printf("%d", A[i]);
        if (i < sizeA - 1) {
            printf(", ");
        }
    }
    printf(" }");
}

// Função para verificar reflexividade
int reflexiva(Par rel[], int n, int A[], int sizeA) {
    for (int i = 0; i < sizeA; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (A[i] == rel[j].x && A[i] == rel[j].y) {
                found = 1;
                break;
            }
        }
        if (!found) return 0;  // Se algum par (a,a) não está presente
    }
    return 1;
}

// Função para verificar antirreflexividade
int antirreflexiva(Par rel[], int n) {
    for (int i = 0; i < n; i++) {
        if (rel[i].x == rel[i].y) return 0;  // Se algum par (a,a) está presente
    }
    return 1;
}

// Função para verificar simetria
int simetrica(Par rel[], int n) {
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (rel[i].x == rel[j].y && rel[i].y == rel[j].x) {
                found = 1;
                break;
            }
        }
        if (!found) return 0;
    }
    return 1;
}

// Função para verificar antissimetria
int antissimetrica(Par rel[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rel[i].x == rel[j].y && rel[i].y == rel[j].x && rel[i].x != rel[i].y) {
                return 0;  // Se (a,b) e (b,a) estão presentes e a != b
            }
        }
    }
    return 1;
}

// Função para verificar transitividade
int transitiva(Par rel[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rel[i].y == rel[j].x) {
                int found = 0;
                for (int k = 0; k < n; k++) {
                    if (rel[i].x == rel[k].x && rel[j].y == rel[k].y) {
                        found = 1;
                        break;
                    }
                }
                if (!found) return 0;
            }
        }
    }
    return 1;
}

int main() {
    int A[MAX] = {1, 2, 3};  // Conjunto A
    Par rel[] = {{1, 2}, {2, 3}, {1, 3}};  // Relação (par ordenado)
    int n = sizeof(rel) / sizeof(rel[0]);  // Número de pares
    int sizeA = sizeof(A) / sizeof(A[0]);  // Tamanho do conjunto A

    // Imprime o conjunto
    printf("Conjunto A: ");
    imprimirConjunto(A, sizeA);
    printf("\n");

    // Verifica as propriedades da relação
    printf("Reflexiva no conjunto A: %s\n", reflexiva(rel, n, A, sizeA) ? "Sim" : "Nao");
    printf("Antirreflexiva no conjunto A: %s\n", antirreflexiva(rel, n) ? "Sim" : "Nao");
    printf("Simetrica no conjunto A: %s\n", simetrica(rel, n) ? "Sim" : "Nao");
    printf("Antissimetrica no conjunto A: %s\n", antissimetrica(rel, n) ? "Sim" : "Nao");
    printf("Transitiva no conjunto A: %s\n", transitiva(rel, n) ? "Sim" : "Nao");

    return 0;
}

/*
    Explicação:
        Entrada: Conjuntos 𝐴 e uma relação representada por pares ordenados.
        Verificações:
            Reflexiva: Todo elemento 𝑥 ∈ 𝐴 deve estar relacionado a si mesmo  (𝑥,𝑥)
            Antirreflexiva: Nenhum elemento 𝑥 ∈ 𝐴  deve estar relacionado a si mesmo.
            Simétrica: Se (𝑥,𝑦) pertence à relação, então (𝑦,𝑥) também deve pertencer.
            Antissimétrica: Se (𝑥,𝑦) e (𝑦,𝑥) pertencem à relação, então 𝑥 =𝑦
            Transitiva: Se (𝑥,𝑦) e (𝑦,𝑧) pertencem à relação, então (𝑥,𝑧) também deve pertencer.
*/
