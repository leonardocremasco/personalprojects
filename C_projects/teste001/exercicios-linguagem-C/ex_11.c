// Exercício 11 -> Calcule a área do círculo

#include <stdio.h>
#include <limits.h>

int main()
{
    const double PI = 3.141592;
    double raio;

    printf("Digite o raio do circulo: ");
    scanf("%lf", &raio);

    // calculando e imprimindo a área do círculo
    if (raio >= 0) {
        double area = PI * raio * raio;
        printf("\n Area do circulo: %lf\n", area);
    }

    return 0;
}
