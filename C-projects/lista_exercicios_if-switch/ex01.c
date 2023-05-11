// Ex. 1 :Desenvolva um programa para comparar a idade de duas pessoas e informar quem é o mais velho  e a diferença entre eles.

#include <stdio.h>

int main() {
   
   int idade1, idade2, diferenca;

   printf("Digite a idade da primeira pessoa: ");
   scanf("%d", &idade1);

   printf("Digite a idade da segunda pessoa: ");
   scanf("%d", &idade2);

   if (idade1 > idade2) {
      diferenca = idade1 - idade2;
      printf("A primeira pessoa e mais velha! Diferença de idade: %d anos", diferenca);
   } else if (idade2 > idade1) {
      diferenca = idade2 - idade1;
      printf("A segunda pessoa eh mais velha! Diferença de idade: %d anos", diferenca);
   } else {
      printf("As duas pessoas tem a mesma idade.");
   }

   return 0;
}