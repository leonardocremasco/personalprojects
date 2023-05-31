// ex. 6

#include <stdio.h>
#include <ctype.h>

int main() {
    int tabela1[5] = {3, 5, 7, 4, 1};
    int tabela2[5] = {1, 4, 7, 5, 3};
    int i, soma_total = 0;

    printf("Tabela 1:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", tabela1[i]);
        soma_total += tabela1[i];
    }

    printf("\n\nTabela 2:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", tabela2[i]);
        soma_total += tabela2[i];
    }

    printf("\n\nSoma total: %d\n", soma_total);

    return 0;
}
