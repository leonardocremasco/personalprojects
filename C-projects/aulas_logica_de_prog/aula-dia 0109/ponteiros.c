
#include <stdio.h>

int main() {
    int a = 3, b = 4;
    int *p, *q;

    // Atribua os endereços de memória das variáveis a e b aos ponteiros p e q
    p = &a;
    q = &b;

    // Use os ponteiros para trocar os valores das variáveis a e b
    int temp = *p; // Armazene o valor de a em uma variável temporária
    *p = *q;       // Atribua o valor de b a a
    *q = temp;     // Atribua o valor temporário a b

    printf("A = %d\n", a); // Deve imprimir "A = 4"
    printf("B = %d\n", b); // Deve imprimir "B = 3"

    return 0;
}
