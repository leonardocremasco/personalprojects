// Aula 19/05/2023 -> Condicionais (if, else)

#include <stdio.h> // biblioteca padrão  comandos de entrada e saída
#include <stdbool.h> // biblioteca que possibilita criar variáveis tipo bool (boleanas)


int main() {

    bool lb_minha_variavel_boleana_verdadeira = true; // declarando e atribuindo o valor Verdadeiro
    bool lb_minha_variavel_boleana_falsa = false;// declarando e atribuindo o valor Falso
    bool lb_minha_variavel_boleana; // só declarando como "booleana“


 printf("Minha variável aqui eh: %d", lb_minha_variavel_boleana_verdadeira);


    printf("\n");

    printf("Minha variável aqui eh: %d", lb_minha_variavel_boleana_falsa);
    printf("\n");


    lb_minha_variavel_boleana = true;

    printf("Minha variável aqui eh: %d", lb_minha_variavel_boleana);

    return 0;

}