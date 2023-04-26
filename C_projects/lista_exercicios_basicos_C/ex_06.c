// Exercício 6 -> Conversão de KM/H em M/S

#include <stdio.h>
#include <limits.h>

int main()
{
    int velo_km;
    int conversao_kmh_ms;
    int velo_ms;

    printf("Digite um valor em km/h: ");
    scanf("%d%*c", &velo_km);

    //  convertendo km/h em m/s a partir da formula: [M = K / 36]

    conversao_kmh_ms = velo_km / 3.6;
    velo_ms = conversao_kmh_ms;

    printf("\n A velocidade de %dKm/h , convertida, eh igual a: %dm/s", velo_km, velo_ms);
    return 0;

}
