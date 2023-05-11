// Ex. 2: desenvolva uma calculadora básica com as 4 operações essenciais (+,-,*,/); dois numeros inteiros; até 3 casas decimais.

#include <stdio.h>

int main() {
  
  int num1, num2;
  char op;
  float result;

  printf("Digite o primeiro numero: ");
  scanf("%d", &num1);

  printf("Digite o segundo numero: ");
  scanf("%d", &num2);

  printf("Digite a operacao (+, -, *, /): ");
  scanf(" %c", &op);

  switch(op) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      result = (float)num1 / num2;
      break;
    default:
      printf("Operacao nao existente\n");
      return 0;
  }

  printf("O resultado eh: %.3f\n", result);

  return 0;
}
