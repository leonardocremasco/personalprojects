// Ex02) Leia uma frase de até 255 caracteres e mostre a qtde de vogais, a qtde de consoantes, a qtde de espaços e a qtde de palavras na frase

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char frase[256];
    int vogais = 0, consoantes = 0, espacos = 0, palavras = 0;
    
    printf("Digite uma frase (até 255 caracteres): ");
    fgets(frase, sizeof(frase), stdin);
    
    // Removendo o caractere de nova linha gerado pelo fgets
    frase[strcspn(frase, "\n")] = '\0';
    
    int i = 0;
    while (frase[i] != '\0') {
        char c = tolower(frase[i]);
        
        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vogais++;
            } else {
                consoantes++;
            }
        } else if (c == ' ') {
            espacos++;
        }
        
        i++;
    }
    
    // contando qtd. de palavras
    i = 0;
    while (frase[i] != '\0') {
        if (isalpha(frase[i])) {
            while (isalpha(frase[i])) {
                i++;
            }
            palavras++;
        } else {
            i++;
        }
    }
    
    printf("Quantidade de vogais: %d\n", vogais);
    printf("Quantidade de consoantes: %d\n", consoantes);
    printf("Quantidade de espaços: %d\n", espacos);
    printf("Quantidade de palavras: %d\n", palavras);
    
    return 0;
}
