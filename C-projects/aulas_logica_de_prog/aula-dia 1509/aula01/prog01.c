
#include <stdio.h>

int main () {

    int a, b;
    int *p, *q; 
    
    a = 3; 
    b = 6;

    p = &a;
    q = &b;

    printf("\n%d", a);
    printf("\n%d", &a);
    printf("\n%d", p);
    printf("\n%d", *p);

    printf("\n%d", b);
    printf("\n%d", &b);
    printf("\n%d", q);
    printf("\n%d", &q);

}