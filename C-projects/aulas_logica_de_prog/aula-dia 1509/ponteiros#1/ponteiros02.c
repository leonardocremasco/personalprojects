
#include <stdio.h>
#include <stdlib.h>

int main () {

    int x;
    int *ptr;

    x = 5;
    ptr = &x;

    printf("O endereco de X eh: %d\n", *ptr); //desreferenciando um ponteiro
    *ptr = 10;
    printf("Agora, X vale: %d\n", *ptr);
}