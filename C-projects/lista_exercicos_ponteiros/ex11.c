// Ex 11)

#include <stdio.h>

int main() {
    int array[5];
    
    printf("Digite 5 numeros inteiros:\n");
    
    // armazenando os valores
    for (int i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }
    
    printf("Enderecos das posicoes com valores pares:\n");
    
    // verificação de posições e dos numeros pares
    for (int i = 0; i < 5; i++) {
        if (array[i] % 2 == 0) {
            printf("Posicao %d: %p\n", i, (void *)&array[i]);
        }
    }
    
    return 0;
}
