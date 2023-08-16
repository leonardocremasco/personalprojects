
#include <stdio.h>
#include <string.h>

int main() {
    char palavra[100];
    char caractere;
    int vogais = 0;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    printf("Digite um caractere: ");
    scanf(" %c", &caractere);

    for (int i = 0; palavra[i] != '\0'; i++) {
        if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u' ||
            palavra[i] == 'A' || palavra[i] == 'E' || palavra[i] == 'I' || palavra[i] == 'O' || palavra[i] == 'U') {
            vogais++;
            palavra[i] = caractere;
        }
    }

    printf("A palavra com as vogais substituidas: %s\n", palavra);
    printf("A palavra tinha %d vogais.\n", vogais);

    return 0;
}
