//  Ex. 3 : Mostrar numeros de 1 a 10 (somente os pares)

#include <stdio.h>

int main() {
    
    int i;

    printf("Numeros pares de 1 a 10:\n");
    
    for (i = 2; i <= 10; i += 2) {
        printf("%d\n", i);
    }

    return 0;
}
