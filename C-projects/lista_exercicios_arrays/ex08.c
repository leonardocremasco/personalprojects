// ex.8

#include <stdio.h>

int main() {
    
    float notas[5];
    float soma = 0.0;
    int i;

    printf("Digite as notas de 5 estudantes: ");
    for (i = 0; i < 5; i++) {
        scanf("%f", &notas[i]);
        soma += notas[i];
    }

    float media = soma / 5.0;

    printf("Notas acima da media:\n");
    for (i = 0; i < 5; i++) {
        if (notas[i] > media) {
            printf("nota: %.2f\n", notas[i]);
        }
    }

    return 0;
}
