// Ex 15

#include <stdio.h>

void imprimirArray(int *array, int tamanho) {
    int *ptr = array; 
    int *end = array + tamanho; 

    
    while (ptr < end) {
        printf("%d ", *ptr); 
        ptr++; 
    }
    printf("\n"); 
}

int main() {
    int meuArray[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(meuArray) / sizeof(meuArray[0]);

    printf("Array: ");
    imprimirArray(meuArray, tamanho);

    return 0;
}
