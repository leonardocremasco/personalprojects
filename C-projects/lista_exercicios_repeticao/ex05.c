// Ex. 5: Ler 7 valores reais e mostrar os maior e o menor deles e motrar resultado

#include <stdio.h>

int main() {
    
    int i;
    float numero, maior, menor;

    printf("Digite 7 valores reais:\n");
    scanf("%f", &numero);
    
    maior = menor = numero;

   
    for (i = 1; i < 7; i++) {
        scanf("%f", &numero);

        if (numero > maior) {
            maior = numero;
        }
        if (numero < menor) {
            menor = numero;
        }
    }

    printf("Maior valor: %.2f\n", maior);
    printf("Menor valor: %.2f\n", menor);

    return 0;
}
