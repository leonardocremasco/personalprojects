
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[50];

    printf("Digite um nome: ");
    scanf("%s", name);

    if (tolower(name[0]) == 'a') {
        printf("O nome comeca com 'a': %s\n", name);
    } else {
        printf("O nome nao comeca com 'a'.\n");
    }

    return 0;
}
