
#ifndef CONTARVOGAISCONSOANTES_H_INCLUDED
#define CONTARVOGAISCONSOANTES_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// função para contar vogais e consoantes
void contarVogaisConsoantes(const char *str, int *vogais, int *consoantes) {
    *vogais = 0;
    *consoantes = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c >= 'a' && c <= 'z') {  // intervalo do alfabeto que usamos
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                (*vogais)++;
            } else {
                (*consoantes)++;
            }
        }
    }
}

#endif