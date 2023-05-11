//Ex. 3: Dado numero do dia da semana (1-7); if composto

#include <stdio.h>

int main() {

  int dia;

  printf("Digite o numero do dia da semana (1-7): ");
  scanf("%d", &dia);

  if (dia == 1) {
    printf("Domingo\n");
  } 
  else if (dia == 2) {
    printf("Segunda-feira\n");
  } 
  else if (dia == 3) {
    printf("Terca-feira\n");
  } 
  else if (dia == 4) {
    printf("Quarta-feira\n");
  } 
  else if (dia == 5) {
    printf("Quinta-feira\n");
  } 
  else if (dia == 6) {
    printf("Sexta-feira\n");
  } 
  else if (dia == 7) {
    printf("Sabado\n");
  } 
  else {
    printf("Dia da semana invalido\n");
  }

  return 0;
}
