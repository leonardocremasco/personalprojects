// Ex03) Leia 5 nomes de até 50 caracteres  e armazene em uma matriz de strings. Depois, leia um nome ou parte dele, e pesquisar na matriz e exibir quando encontrado

#include <stdio.h>
#include <string.h>

#define NUM_NAMES 5
#define MAX_NAME_LENGTH 50

int main() {
   
    char names[NUM_NAMES][MAX_NAME_LENGTH];
    char searchName[MAX_NAME_LENGTH];
    
    // lendo os nomes e armazenando na matriz
    printf("Digite os %d nomes de até %d caracteres:\n", NUM_NAMES, MAX_NAME_LENGTH);
    for (int i = 0; i < NUM_NAMES; i++) {
        printf("Nome %d: ", i + 1);
        scanf("%s", names[i]);
    }
    
    // pedindo nome/parte dele para ser pesquisado
    printf("Digite um nome ou parte dele para pesquisar: ");
    scanf("%s", searchName);
    
    
    printf("Nomes encontrados:\n");
    for (int i = 0; i < NUM_NAMES; i++) {
        if (strstr(names[i], searchName) != NULL) {
            printf("%s\n", names[i]);
        }
    }
    
    return 0;
}
