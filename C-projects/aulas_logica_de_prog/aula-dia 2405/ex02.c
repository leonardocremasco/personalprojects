// do while

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
    printf("O tamanho da variavel lc_meu_nome %d", li_t);
    printf("\n printando cada letra do nome:");

    // for (li_i=0;li_i<li_t;li_i++){
    //     printf("\n %da letra: %c",(li_i+1), toupper(lc_meu_nome[li_i]));
    // }

    li_i=0;

    do
    {
        printf("\n %da letra: %c", (li_i+1), toupper(lc_meu_nome[li_i]));
        li_i++;
    } while (li_i<li_t);
    
    

    return 0;
}