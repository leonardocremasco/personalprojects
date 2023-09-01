// Ex01) Calculadora Simples

#include <stdio.h>
#include <math.h>
#include "divisao.h"
#include "multiplicacao.h"
#include "adicao.h"
#include "subtracao.h"

// rodando a calculadora
int main() {
    float num1, num2;
    char operacao;

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);

    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    printf("Escolha a operacao (+ para adicao, - para subtracao, * para multiplicacao, / para divisao): ");
    scanf(" %c", &operacao);

    float resultado;

    switch (operacao) {
        case '+':
            resultado = adicao(num1, num2);
            break;
        case '-':
            resultado = subtracao(num1, num2);
            break;
        case '*':
            resultado = multiplicacao(num1, num2);
            break;
        case '/':
            resultado = divisao(num1, num2);
            break;
        default:
            printf("Operacao invalida.\n");
            return 1; // Código de erro
    }

    printf("Resultado: %.2f\n", resultado);

    return 0;
}
