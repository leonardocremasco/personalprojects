#include <stdio.h>
#include <limits.h>

#define MAX_N 100

int min(int a, int b) {
    return a < b ? a : b;
}

int tempoMinimo(int tempos[], int n) {
    if (n == 1) return tempos[0];
    if (n == 2) return tempos[1];
    if (n == 3) return tempos[0] + tempos[1] + tempos[2];
    
    int op1 = tempos[1] + tempos[0] + tempos[n-1] + tempos[1];
    int op2 = tempos[n-1] + tempos[0] + tempos[n-2] + tempos[0];
    
    return min(op1, op2) + tempoMinimo(tempos, n-2);
}

int main() {
    int tempos[MAX_N], n;
    
    printf("Entre com o numero de pessoas: ");
    scanf("%d", &n);
    
    printf("Entre com os tempos de travessia: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tempos[i]);
    }
    
    // Ordena os tempos em ordem crescente (usando bubble sort)
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (tempos[j] > tempos[j+1]) {
                int temp = tempos[j];
                tempos[j] = tempos[j+1];
                tempos[j+1] = temp;
            }
        }
    }
    
    int resultado = tempoMinimo(tempos, n);
    printf("Tempo minimo para atravessar a pont: %d minutos\n", resultado);

    return 0;
}