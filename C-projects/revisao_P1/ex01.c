#include <stdio.h>

int calcularMinimoViagens(int A, int C) {
    if ( A <= C) {
        return 1; 
    }else {
        int viagens = (A - 1) / (C - 1) + 1;
        return viagens;
    }
}

int main() {
    int A, C;

    printf("Digite o numero total de aventureiros: ");
    scanf("%d", &A);

    printf("Digite a capacidade do teleferico: ");
    scanf("%d", &C);

    int minimoViagens = calcularMinimoViagens(A, C);

    printf("Numero minimo de viagens necessarias: %d\n", minimoViagens);

    return 0;
}
