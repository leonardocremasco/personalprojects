
#ifndef FAHRENHEITPARACELSIUS_H_INCLUDED
#define FAHRENHEITPARACELSIUS_H_INCLUDED

#include <stdio.h>

double FahrenheitParaCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

#endif