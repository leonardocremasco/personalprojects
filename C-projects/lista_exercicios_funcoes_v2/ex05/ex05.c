// Ex05) Vogais ou Consoantes

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contarVogaisConsoantes.h"

int main() {
    char frase[100];
    int vogais, consoantes;

    printf("Insira uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    // removendo o caractere de nova linha do final da entrada
    frase[strcspn(frase, "\n")] = '\0';

    contarVogaisConsoantes(frase, &vogais, &consoantes);

    printf("Numero de vogais: %d\n", vogais);
    printf("Numero de consoantes: %d\n", consoantes);

    return 0;
}
