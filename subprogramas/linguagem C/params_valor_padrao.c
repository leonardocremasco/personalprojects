
//Em C não podemos fazer assim como em C++, onde podemos passar os valores padrões dos parâmetros em sua declaração. Em vez disso, o que podemos fazer é utilizar macros ou definindo outras funções com um numero diferente de parâmetros.

#include <stdio.h>
#include <stdlib.h>

// função original com todos os parâmetros
void printValues(int a, int b) {
    printf("a = %d, b = %d\n", a, b);
}

// função que usa um valor padrão para o segundo parâmetro
void printValuesDefault(int a) {
    printValues(a, 10); // 10 é o valor padrão para b
}