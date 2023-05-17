//  Ex. 10: Fazer cálculo deo IR com base na tabela

#include <stdio.h>

float calcularImposto(float baseCalculo) {
    if (baseCalculo <= 1637.11) {
        return 0;
    } else if (baseCalculo >= 1637.12 && baseCalculo <= 2453.50) {
        return (baseCalculo * 0.075) - 122.78;
    } else if (baseCalculo >= 2453.51 && baseCalculo <= 3271.38) {
        return (baseCalculo * 0.15) - 306.80;
    } else if (baseCalculo >= 3271.39 && baseCalculo <= 4087.65) {
        return (baseCalculo * 0.225) - 552.15;
    } else {
        return (baseCalculo * 0.275) - 756.53;
    }
}

int main() {
    float baseCalculo, impostoDevido;
    
    printf("Digite a base de calculo mensal: ");
    scanf("%f", &baseCalculo);
    
    impostoDevido = calcularImposto(baseCalculo);
    
    printf("Imposto devido: R$%.2f\n", impostoDevido);
    
    return 0;
}
