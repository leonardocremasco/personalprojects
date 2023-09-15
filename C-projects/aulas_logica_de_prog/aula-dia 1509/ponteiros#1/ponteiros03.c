
#include <stdio.h>
#include <locale.h>

int main () {
    
    setlocale(LC_ALL,"Portuguese");

    int a, b, c;
    int *ptr;

    a = 90;
    b = 2;
    c = 3;

    ptr = &a;

    printf("Valor de ptr: %p, \nConteudo de ptr: %d\n", ptr, *ptr);
    printf("B: %d, C: %d", b, c);
}