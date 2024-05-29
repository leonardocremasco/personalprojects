
// Ambientes em referenciais locais: variáveis estáticas e dinâmicas
// Em C, temos ambos os exemplos, onde normalmente seu padrão é a chamada stack-dinâmica, onde por padrão ela  é estática, mas por meio de subprogramas (funções) ou de sentenças propostas pelo código pode ser alterada (tornando-se dinâmica).

#include <stdio.h>
#include <stdlib.h>

int somador (int array[], int array_tam)
{
    static int soma = 0; // --> aqui é onde a variável se torna ESTÁTICA
    
}
    