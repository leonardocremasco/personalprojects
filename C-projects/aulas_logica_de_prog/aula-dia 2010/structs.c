
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

    struct cadastro c;

    strcpy(c.nome, "LEONARDO");
    c.idade = 18;
    strcpy(c.rua, "Rua Felgueiras");
    c.numero = 291;

    printf("Numero: %d\n", c.numero);
    printf("Idade: %d\n", c.idade); 
    printf("Endereco: %s\n", c.rua);
    printf("Nome: %s", c.nome);
}