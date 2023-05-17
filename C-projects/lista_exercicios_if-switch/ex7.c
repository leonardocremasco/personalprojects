// Ex. 7: dado o numero do mês do ano, escreva o extenso correspondente e qual o semestre que se encontra esse mês.

#include <stdio.h>
#include <stdbool.h>

int main () {

    int mes;

    printf("Digite um mes do ano em numeral, e escreverei \no seu extenso correspondente e qual semestre esse mesmo mes pertence: ");
    scanf("%d", &mes);

    switch (mes)
    {
    case 1:
        printf("JANEIRO; pertence ao 1 semestre.");
        break;
    
    case 2:
        printf("FEVEREIRO; pertence ao 1 semestre.");
        break;
    case 3:
        printf("MARCO; pertence ao 1 semestre.");
        break;  
    case 4:
        printf("ABRIL; pertence ao 1 semestre.");
        break;
    case 5:
        printf("MAIO; pertence ao 1 semestre.");
        break;
    case 6:
        printf("JUNHO; pertence ao 1 semestre.");
        break;
    case 7:
        printf("JULHO; pertence ao 2 semestre.");
        break;
    case 8:
        printf("AGOSTO; pertence ao 2 semestre.");
        break;
    case 9:
        printf("SETEMBRO; pertence ao 2 semestre.");
        break;
    case 10:
        printf("OUTUBRO; pertence ao 2 semestre.");
        break;
    case 11:
        printf("NOVEMBRO; pertence ao 2 semestre.");
        break;
    case 12:
        printf("DEZEMBRO; pertence ao 2 semestre.");
        break;
    default:
        printf("O numero colocado nao corresponde a nenhum mes.");
        break;
    }

    return 0;
}