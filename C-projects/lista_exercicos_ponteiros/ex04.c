
#include <stdio.h>

void trocarValor(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b= temp;
}

int main () {
    int valorA, valorB;

    printf("Digite o valor de A: ");
    scanf("%d", &valorA);

    printf("Digite o valor de B: ");
    scanf("%d", &valorB);

    trocarValor(&valorA, &valorB);

    printf("Valores apos a inversao:\n");
    printf("A: %d\n", valorA);
    printf("B: %d\n", valorB);

    return 0;
}