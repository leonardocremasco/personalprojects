// ex.7

#include <stdio.h>
#include <ctype.h>
#define SIZE 10

int main() {
    double numeros[SIZE] = {-1.7, 3.0, 0.0, 1.5, 0.0, -1.7, -1.5, 2.3, -1.7, 3.0};
    int ocorrencias[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (numeros[i] == numeros[j]) {
                ocorrencias[i]++;
            }
        }
    }

    printf("Numero\tOcorrencias\n");
    for (int i = 0; i < SIZE; i++) {
        if (ocorrencias[i] > 0) {
            printf("%.1f\t%d\n", numeros[i], ocorrencias[i]);
        }
    }

    return 0;
}
