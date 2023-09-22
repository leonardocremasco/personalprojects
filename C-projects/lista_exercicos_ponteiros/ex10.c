// Ex 10)

#include <stdio.h>

int main () {

    int array [5];
    
    printf("Digite 5 numeros inteiros: ");
    
    // armazenando os valores na array
    for (int i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }

    printf("O dobro dos valores lidos:\n");

    for (int i = 0; i < 5; i++) {
        int *ptr = &array[i];

        printf("Valor %d = %d\n", *ptr, *ptr * 2);  
    }
    
    return 0;


}