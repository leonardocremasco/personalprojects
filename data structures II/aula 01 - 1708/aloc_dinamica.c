
#include <stdio.h>
#include <stdlib.h>

int main() {
    double *v1, *v2, prodEsc;
    int n,i;

    printf("Digite a dimensao dos vetores:");
    scanf("%d", &n);
    v1 = malloc(n*sizeof(double));
    v2 = malloc(n*sizeof(double));

    printf("Digite os dados de v1:");
    for (i = 0; i < n; i++){
        scanf("%lf", &v1[i]);
    }
    
    printf("Digite os dados de v2:");
    for (i = 0; i <n; i++){
        scanf("%lf", &v2[i]);   
    }
    
    prodEsc = 0;
    for (i = 0; i < n; i++){
        prodEsc = prodEsc + (v1[i] + v2[i]);
    }
    
    printf("Resposta: %.2lf\n", prodEsc);
    free(v1);
    free(v2);
}