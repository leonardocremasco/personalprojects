
#include <stdio.h>
#include <string.h>

void CesarEncrypt(char *text, int space) {
    int length = strlen(text);
    
    for (int i = 0; i < length; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + space) % 26) + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + space) % 26) + 'a';
        }
    }
}

int main() {
    char mensagem[100];

    printf("Digite a mensagem a ser codificada: ");
    fgets(mensagem, sizeof(mensagem), stdin);

    CesarEncrypt(mensagem, 3);

    printf("Mensagem codificada: %s\n", mensagem);

    return 0;
}
