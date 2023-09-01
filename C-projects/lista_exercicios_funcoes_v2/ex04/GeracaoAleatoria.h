
#ifndef GERACAOALEATORIA_H_INCLUDED
#define GERACAOALEATORIA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GeracaoAleatoria(int min, int max) {
    return min + rand() % (max - min + 1);
}

#endif