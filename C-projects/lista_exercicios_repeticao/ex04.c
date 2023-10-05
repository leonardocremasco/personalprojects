// Ex. 4 = tabuada

#include <stdio.h>

int main () {

    int i, x;
    
        for (i = 1; i <=10; i++) {
            printf("TABUADA DO %d \n", i);
            for (x = 1; x <= 10; x++){
                printf(" %d X %d = %d \n", i, x, i*x);
            }
            
            printf("************ \n");
        }

        return 0;
        
}