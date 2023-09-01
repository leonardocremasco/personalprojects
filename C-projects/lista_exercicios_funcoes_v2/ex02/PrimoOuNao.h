
#ifndef PRIMOOUNAO_H_INCLUDED
#define PRIMOOUNAO_H_INCLUDED

int PrimoOuNao(int num) {
    if (num <= 1) {
        return 0; // nº menores ou iguais a 1 não sao primos
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // encontrou um divisor, portanto não é primo
        }
    }
    
    return 1; // se não encontrou divisores, é primo
}

#endif