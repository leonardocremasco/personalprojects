// Ex. 11: ler dois números e comparar se são iguais, quem é o maior e quem é o menor

#include <stdio.h>
#include <stdbool.h>

int main () {

    double n1;
    double n2;

    printf("Digite um numero: ");
    scanf("%lf", &n1);
    printf("Digite outro numero: "); 
    scanf("%lf", &n2);

    if (n1 == n2)
    {
        printf("Os dois numeros sao IGUAIS.");
    } else if (n1 > n2) {
        printf("o numero %lf eh o MAIOR numero, e %lf eh o MENOR numero.", n1, n2);
    } else if (n2 > n1) {
        printf("O numero %lf eh o MAIOR numero, e o numero %lf eh o MENOR numero. ", n2, n1);
    }
    
    return 0;   
}