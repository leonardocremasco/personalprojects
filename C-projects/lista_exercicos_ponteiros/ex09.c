// Ex 09)

#include <stdio.h>

int main() {
    float matriz[3][3]; 
    
    // inicializando a matriz com valores
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = i * 3 + j + 1; 
        }
    }
    
    printf("Enderecos de cada posicao da matriz:\n");
    
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            float *ptr = &matriz[i][j]; 
            printf("Endereco da posicao [%d][%d]: %p\n", i, j, (void *)ptr);
        }
    }
    
    return 0;
}
