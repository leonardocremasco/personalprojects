// ex.9

#include <stdio.h>
#include <ctype.h>
#define NOTAS 100

int main () {

    int i;
    float media = 0;

    printf("Digite as notas dos estudantes:\n");
    for (i = 0; i < NOTAS; i++){
        printf("Nota do estudante %d:", i);
        scanf("%f", &NOTAS[i]);
    }

    for (i = 0; i < NOTAS; i++) {
        media = media + NOTAS[i];
        media = media/100;
    }
        
    
}