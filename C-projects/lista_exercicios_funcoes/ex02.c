// Ex02) Verificação se o número é primo

#include <stdio.h>
#include <math.h>

// Verificação se um número é primo
int PrimoOuNao(int num) {
    if (num <= 1) {
        return 0; // nº menores ou iguais a 1 não sao primos
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // encontrou um divisor, portanto não é primo
        }
    }
    
    return 1; // se não encontrou divisores, é primo
}

int main() {
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    if (PrimoOuNao(num)) {
        printf("%d EH um numero primo.\n", num);
    } else {
        printf("%d NAO EH um numero primo.\n", num);
    }

    return 0;
}
