
#include <stdio.h>
#include <string.h>

int main() {
    
    char name[100];
    int num_words = 0;

    printf("Digite um nome: ");
    scanf("%s", name);

    // calculando a qtd de letras
    num_words = strlen(name);

    printf("O nome \"%s\" tem %d letras.\n", name, num_words);

    return 0;
}
