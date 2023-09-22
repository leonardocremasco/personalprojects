// Ex. 02)

#include <stdio.h>

int main() {
    int num1 = 35;
    int num2= 90;

    int *ptr1 = &num1; 
    int *ptr2 = &num2; 

    printf("Endereco do 1 valor: %p\n", (void *)ptr1);
    printf("Endereco do 2 valor: %p\n", (void *)ptr2);

    if (ptr1 > ptr2) {
        printf("O maior endereco é: %p\n", (void *)ptr1);
    } else if (ptr2 > ptr1) {
        printf("O maior endereco é: %p\n", (void *)ptr2);
    } else {
        printf("Os endereços são iguais.\n");
    }

    return 0;
}
