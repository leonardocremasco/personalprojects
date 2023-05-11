

#include <stdbool.h>// biblioteca que possibilita criar variáveis tipo bool (boleanas)
#include <stdio.h>


int main() {

    int li_x = 10;

    int li_y = 15;



    printf("X=10 eh menor que Y=15 : %d", li_x < li_y);

    printf("\n");

    printf("X=10 eh maior que Y=15 : %d", li_x > li_y);

    printf("\n");

    printf("X=10 eh igual a Y=15 : %d", li_x == li_y);
    printf("\n");

    printf("X=10 não eh igual a Y=15 : %d", li_x != li_y);
    printf("\n O valor 1(um)representa uma Comparação VERDADEIRA enquanto o 0(zero) representa FALSO");


 return 0;

}