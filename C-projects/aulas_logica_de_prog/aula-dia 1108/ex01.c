
#include <stdio.h>
#define size 50

int main () {

    char s[50];

    printf("Digite seu nome: ");
    fgets(s, 5, stdin);

    printf("%s", s);

    return 0;
}