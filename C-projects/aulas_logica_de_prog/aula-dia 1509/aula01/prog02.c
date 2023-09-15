
#include <stdio.h>

int main () {

    int a = 5;
    int b = 10;
    int *ptrA = &a;
    int *ptrB = &b;
    int temp;

    temp = *ptrA; // atribuindo valor de a em temp
    *ptrA = *ptrB; // atribuindo valor de b em A
    *ptrB = temp;

    printf("Depois da troca: a=%d, b=%d", a, b);


}