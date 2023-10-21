
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cadastro {

    char nome[50];
    int idade;
    char rua[50];
    int numero;

};

int main () {

    struct cadastro c[4];

    int i;
    for (i=0; i<4; i++){
        gets(c[i].nome);
        scanf("%d", &c[i].idade);
        gets(c[i].rua);
        scanf("%d", &c[i].numero);
    }

    for (i = 0; i < 4; i++){
        printf("Numero: %d\n", c[i].numero);
        printf("Idade: %d\n", c[i].idade); 
        printf("Endereco: %s\n", c[i].rua);
        printf("Nome: %s", c[i].nome);
    }
    

    
    
}