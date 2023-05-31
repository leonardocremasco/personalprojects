// ex. 2

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int numero, soma = 0, quantidade = 0;
    
    do {
        printf("Digite um numero inteiro (digite 0 para sair): ");
        scanf("%d", &numero);
        
        soma += numero;
        quantidade++;
    } while (numero != 0);
    
    if (quantidade > 1) {
        printf("A quantidade de numeros somados eh: %d\n", quantidade - 1);
    } else {
        printf("Nenhum numero foi somado.\n");
    }
    
    return 0;
}
