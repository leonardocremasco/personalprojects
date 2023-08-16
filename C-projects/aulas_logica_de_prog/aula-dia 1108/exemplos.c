
#include <stdio.h>
#define size 3

int main (){

    char s[20];
    printf("Digite sua frase:");
    //scanf ("%s", s)
    fgets(s,20, stdin);
    printf("%s", s);
}