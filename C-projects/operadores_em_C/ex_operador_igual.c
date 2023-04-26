// operador: IGUALDADE

#include <stdio.h>
#include <math.h>

int igualdade (int p1, int p2)
{
    int produto;
    produto = (p1 = p2);
    return produto;
}

int main ()
{
    int primeiro_valor;
    int segundo_valor;

    printf("Digite um valor inteiro para (x): ");
    scanf("%d%*c", &primeiro_valor);

    printf("Digite um valor inteiro para (y): ");
    scanf("%d%*c", &segundo_valor);

    if (primeiro_valor == segundo_valor) {
        printf("Os valores de (%d) e (%d) sao iguais.", primeiro_valor, segundo_valor);
    } else {
        printf("Os valores de (%d) e (%d) sao diferentes", primeiro_valor, segundo_valor);
    }
    
    return 0;

}

