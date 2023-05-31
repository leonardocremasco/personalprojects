// ex. 6

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int count = 0;
    double sum = 0.0;
    double number;

    printf("Digite numeros reais maiores que zero (digite 0 para sair):\n");

    do {
        printf("Numero: ");
        scanf("%lf", &number);

        if (number > 0) {
            sum += number;
            count++;
        }
    } while (number != 0);

    if (count > 0) {
        double media = sum / count;
        printf("Quantidade de numeros: %d\n", count);
        printf("Media dos numeros: %.2lf\n", media);
    } else {
        printf("Nenhum numero valido foi inserido.\n");
    }

    return 0;
}
