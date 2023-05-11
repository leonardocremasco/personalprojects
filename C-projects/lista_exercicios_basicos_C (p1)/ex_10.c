//  Exercício 10 -> Divisão entre os três ganhadores [R$ 780.000,00]

#include <stdio.h>
#include <limits.h>

int main ()
{
    float quantia_total = 780.000;
    float ganhador_1;
    float final_ganhador_1;
    float ganhador_2;
    float final_ganhador_2;
    float ganhador_3;
    float final_ganhador_3;

    // valor recebido ao ganhador 1
    ganhador_1 = quantia_total * 0.46;
    final_ganhador_1 = ganhador_1;

    // valor recebido ao ganhador 2
    ganhador_2 = quantia_total * 0.32;
    final_ganhador_2 = ganhador_2;

    // valor recebido ao ganhador 3
    ganhador_3 = quantia_total * 0.22;
    final_ganhador_3 = ganhador_3;

    printf("As respectivas quantias recebidas foram, de acordo com a porcentagem de cada um: \n1 lugar: %f \n 2 lugar: %f  \n 3 lugar: %f ", final_ganhador_1, final_ganhador_2, final_ganhador_3);
}
