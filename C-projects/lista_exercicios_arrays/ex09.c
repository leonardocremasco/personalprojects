// ex.9

#include <stdio.h>
#include <ctype.h>

#define NOTAS 100

int main () {
    
    int i;
    float media_1;
    float media_2 = 0;

    printf("Digite as notas dos estudantes\n");
    for (i = 0; i < NOTAS; i++){
        printf("Nota do estudante %d:", i);
        scanf("%f", &media_1);
    }

    for (i = 0; i < NOTAS; i++){
        media_2 = media_2 + media_1;
        media_2 = media_2 / NOTAS;
    }

    for (i = 0; i < NOTAS; i++){
        if (media_1 > media_2)
        {
            printf("Notas: %f\n", media_1);
        }
        
    }
    
    return 0;
    
}