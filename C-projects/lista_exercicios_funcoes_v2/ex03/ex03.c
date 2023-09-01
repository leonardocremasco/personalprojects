// Ex03) Conversão de temperatura (Celsius para Fahrenheit)

#include <stdio.h>
#include <math.h>
#include "FahrenheitParaCelsius"
#include "CelsiusParaFahrenheit.h"

int main() {
    int choice;
    double temperature;

    printf("Escolha a conversao:\n");
    printf("1. Celsius para Fahrenheit\n");
    printf("2. Fahrenheit para Celsius\n");
    printf("\n");
    printf("Conversao: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Digite a temperatura em graus Celsius: ");
        scanf("%lf", &temperature);

        double convertedTemperature = CelsiusParaFahrenheit(temperature);

        printf("%.2lf graus Celsius equivalem a %.2lf graus Fahrenheit.\n", temperature, convertedTemperature);
    } else if (choice == 2) {
        printf("Digite a temperatura em graus Fahrenheit: ");
        scanf("%lf", &temperature);

        double convertedTemperature = FahrenheitParaCelsius(temperature);

        printf("%.2lf graus Fahrenheit equivalem a %.2lf graus Celsius.\n", temperature, convertedTemperature);
    } else {
        printf("Escolha invalida.\n");
    }

    return 0;
}
