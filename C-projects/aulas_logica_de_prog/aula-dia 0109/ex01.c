// Trabalhando com funções em C (void, int, float, etc)

#include <stdio.h>
#include <math.h>
#include "soma.h"
#include "potencia.h"
#include "par.h"

int main()
{
    float x;
    int op = 0;
    float p;

    while (op!=4){
        system("cls"); ///limpar a tela
        printf("\n1-Soma\n2-Par\n3-Potencia\n4-Sair  ");
        scanf("%d",&op);
        if (op==1){
            soma();
        }
        if (op==2){
            x = par();
            if (x==0){
                printf("Numero par");
            }
            else{
                printf("Numero impar");
            }
        }
        if (op==3){
            potencia();
        }
        if (op==4){
            printf("\nPressione um tecla para finalizar.");
            getch();///aguarda pressionar uma tecla
            break;
        }

        printf("\nPressione um tecla para continuar...");
        getch();
    }

    return 0;
}
