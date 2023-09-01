// Ex05) Vogais ou Consoantes

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// função para contar vogais e consoantes
void contarVogaisConsoantes(const char *str, int *vogais, int *consoantes) {
    *vogais = 0;
    *consoantes = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c >= 'a' && c <= 'z') {  // intervalo do alfabeto que usamos
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                (*vogais)++;
            } else {
                (*consoantes)++;
            }
        }
    }
}

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
