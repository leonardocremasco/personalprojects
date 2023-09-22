// Ex 08)

#include <stdio.h>

int main () {

    float array[10];

    for (int i = 0; i < 10; i++){
        array[i] = i * 3;
    }

    printf("Enderecos de cada posicao na array:\n");

    for (int i = 0; i < 10; i++) {
        float *ptr = &array[i];
        printf("Endereco da posicao [%d]: %p\n", i, (void *)ptr);
    }
    
    return 0;
}