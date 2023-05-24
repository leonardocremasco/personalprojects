

#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main() {
    char lc_meu_nome[] = "Leonardo Cremasco Bernardes Boscariol";
    char lc_sexo='M';
    int li_i;
    int li_t=strlen(lc_meu_nome);


    printf("Meu nome eh %s e meu sexo eh %c", lc_meu_nome,lc_sexo);
    printf("\n");
    printf("O tamanho da variavel lc_meu_nome %d",li_t);




    printf("\n printando cada letra do nome:");
    /*
    printf("\n 1a letra: %c", lc_meu_nome[0]);
    printf("\n 2a letra: %c", lc_meu_nome[1]);
    printf("\n 3a letra: %c", lc_meu_nome[2]);
    printf("\n 4a letra: %c", lc_meu_nome[3]);
     printf("\n 5a letra: %c", lc_meu_nome[4]);
    printf("\n 6a letra: %c", lc_meu_nome[5]);
    printf("\n 7a letra: %c", lc_meu_nome[6]);
    */
    for (li_i=0;li_i<li_t;li_i++){
     printf("\n %da letra: %c",(li_i+1), toupper(lc_meu_nome[li_i]));
    }



    return 0;
}