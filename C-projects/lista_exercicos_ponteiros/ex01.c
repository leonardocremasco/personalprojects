// Ex 01)

#include <stdio.h>

int main() {
    int inteiro = 42;
    float real = 3.14;
    char caractere = 'A';

    // declarando os ponteiros para as variáveis
    int *ptrInteiro = &inteiro;;
    float *ptrReal =  &real;
    char *ptrCaractere = &caractere;

   
    printf("Valores originais:\n");
    printf("Inteiro: %d\n", inteiro);
    printf("Real: %.2f\n", real);
    printf("Caractere: %c\n", caractere);

    // modificando os valores originais
    *ptrInteiro = 100;
    *ptrReal = 2.718;
    *ptrCaractere = 'B';

    
    printf("\nValores apos a modificacao:\n");
    printf("Inteiro: %d\n", inteiro);
    printf("Real: %.2f\n", real);
    printf("Caractere: %c\n", caractere);

    return 0;
}
