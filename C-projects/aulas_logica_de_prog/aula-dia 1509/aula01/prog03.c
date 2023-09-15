
#include <stdio.h>

int main () {
    
    int vet [] = {1,2,3,4,5};
    int *ptr;
    int soma = 0;

    ptr = vet;

    for (int i = 0; i < 5; i++){
        soma += *ptr;
        ptr++;
    }

    printf("\nA soma dos elementos do vetor: %d", soma);
    

    return 0;
}