// Ex 05)

#include <stdio.h>

void compararValores (int *a, int *b) {
    if (*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }else if (*b > *a){
        int temp = *b;
        *b = *a;
        *a = temp;
    }
    
}

int main () {

    int valor1, valor2;

    printf("Digite o primeiro valor:");
    scanf("%d", &valor1);

    printf("Digite o segundo valor: ");
    scanf("%d", &valor2);

    compararValores(&valor1, &valor2);

    printf("Maior valor: %d\n", valor1);
    printf("Menor valor: %d\n", valor2);

    return 0;
}