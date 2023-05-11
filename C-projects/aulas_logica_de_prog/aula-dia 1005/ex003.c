// Programa que lê se é dia de semana ou não

#include <stdio.h>
#include <stdbool.h>

int main () {

    int li_dia;

    printf("Entre com um numero correspondente a um dia da semana (1-7): ");
    scanf("%d%*c", &li_dia);

    printf("O numero digitado foi o %d dia", li_dia);

    switch (li_dia){
    case 1:
        printf("Domingo");
        break;
    case 2:
        printf("Segunda");
        break;
    case 3:
        printf("Terca");
        break;
    case 4:
        printf("Quarta");
        break;
    case 5:
        printf("Quinta");
        break;
    case 6:
        printf("Sexta");
        break;
    case 7:
        printf("Sabado");
        break;

    default:
        printf(" , mas %d Nao eh dia da semana valido ", li_dia);
        break;
    }

    return 0;
}