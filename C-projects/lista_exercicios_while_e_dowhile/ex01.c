// Ex. 1

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    
    int numero, soma = 0, quantidade = 0;
    
    printf("Digite um número inteiro (digite 0 para sair): ");
    scanf("%d", &numero);
    
    while (numero != 0) {
        soma += numero;
        quantidade++;
        
        printf("Digite um número inteiro (digite 0 para sair): ");
        scanf("%d", &numero);
    }
    
    if (quantidade > 0) {
        printf("A quantidade de números somados é: %d\n", quantidade);
    } else {
        printf("Nenhum número foi somado.\n");
    }
    
    return 0;
}
