// Estruturas de repetição (for) -> usado quando sabemos o numero de repetições

#include <stdio.h>

int main() {
    
    int i, x, y;

    for (i = 1; i <=3; i++) {
        for (x= 1; x <=3; x++){
            for (y = 1; y <= 3; y++) {
                printf("looping atraves do i=%d for x=%d e y=%d\n", i, x, y);
            }
            
        }
        printf("********\n", i);
    }
    
    return 0;
}