// Ex1) Faça um programa que realize o produto vetorial

#include <stdio.h>
#include <stdlib.h>

int main () {
    
    int tamanho;

    printf("--------------------------------\n");
    printf("CALCULADOR DE PRODUTO ESCALAR\n");
    printf("--------------------------------\n");
    
    printf("\nDigite o tamanho dos vetores: ");
    scanf("%d", &tamanho);

    double vet1[tamanho], vet2[tamanho];

    //pegando elementos do 1 vetor
    printf("Digite os elementos do primeiro vetor:\n ");
    for(int i = 0; i < tamanho; i++) {
        printf("Elemento [%d]: ", i + 1);
        scanf("%lf", &vet1[i]);
    }

    //pegando elementos do 2 vetor
    printf("Digite os elementos do segundo vetor:\n ");
    for(int i = 0; i < tamanho; i++) {
        printf("Elemento [%d]: ", i+ 1);
        scanf("%lf", &vet2[i]);
    }

    //calculando produto escalar com cada elemento pela iteração
    double p_escalar = 0;
    for(int i = 0; i < tamanho; i++){
        p_escalar += vet1[i] * vet2[i];
    }

    //exibindo os vetores com seus elementos
    printf("\nVetor 1: ");
    for(int i= 0; i < tamanho; i++){
        printf("%lf", &vet1[i]);
    } 

    printf("\nVetor 2: ");
    for(int i= 0; i < tamanho; i++){
        printf("%lf", &vet2[i]);
    } 

    //exibindo o produto escalar
    printf("\n \nO produto escalar entre os dois vetores eh de: %f\n", p_escalar);

    return 0;
}