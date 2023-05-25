// exercicio 3

#include<stdio.h>
#include <stdbool.h>   // biblioteca que possibilita criar variáveis tipo bool (boleanas)

int main(){
    
    int li_n=0;
    int li_vezes=0;
    int li_soma = 0;
    bool lb_looping = true;


    while(lb_looping){
        li_soma = li_soma + 1;
        li_n++;
        printf("\nA soma para a vez %d eh %d ", li_n,li_soma);

        if  (li_soma >= 10){
            lb_looping=false;
        }

    }

    return 0;
}

