// ex. 4

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int valor;
    
    printf("Digite um valor: ");
    scanf("%d", &valor);
    
    while (valor >= 0) {
        valor -= 2;
    }
    
    printf("O valor final eh: %d\n", valor);
    
    return 0;
}
