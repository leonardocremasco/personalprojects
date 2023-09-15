
#include <stdio.h>
#include <string.h>

int main() {
    char *ptr;
    char frase[255];
    int contaPalavras = 0;
    int dentroDePalavra = 0;

    printf("\nDigite uma frase:");
    fgets(frase, 255, stdin);

    ptr = frase;

    while (*ptr != '\0') {
        if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r' || *ptr == '\0') {
            if (dentroDePalavra) {
                dentroDePalavra = 0; 
                contaPalavras++;
            }
        } else {
            dentroDePalavra = 1; 
        }
        ptr++;
    }

    printf("\nQtde de palavras na frase: %d\n", contaPalavras);

    return 0;
}
