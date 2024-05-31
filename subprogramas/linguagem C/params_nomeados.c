
// Definição de parâmetros nomeados em C.

// Em C não temos diretamente o recurso de passar parametros nomeados, assim como o exemplo em ADA dado no slide. No entanto, podemos adaptar o mesmo usando as STRUCTS.

#include <stdio.h>

// definindo uma estrutura para simularmos parâmetros nomeados
typedef struct {
    int comprimento;
    int *lista;
    int *soma;
} SomadorParams;

void SOMADOR(SomadorParams params) { // chamada da função
    *(params.soma) = 0; // Inicializa a soma

    // Itera sobre a lista somando os elementos
    for (int i = 0; i < params.comprimento; i++) {
        *(params.soma) += params.lista[i];
    }
}

int main() {
    int meu_comprimento = 5;
    int meu_array[] = {1, 2, 3, 4, 5};
    int minha_soma;

    // inicializando a estrutura com os parâmetros
    SomadorParams params;
    params.comprimento = meu_comprimento;
    params.lista = meu_array;
    params.soma = &minha_soma;

    // Chama a função SOMADOR
    SOMADOR(params);

    // Imprime o resultado
    printf("A soma dos elementos é: %d\n", minha_soma);

    return 0;
}

