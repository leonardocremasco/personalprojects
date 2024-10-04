//  considerações: S(n,k)=k×S(n−1,k)+S(n−1,k−1)  com as condições iniciais:
// S(0,0)=1;
// S(n,0)=0 para n>0 
// S(0,k)=0 para k>0

#include <stdio.h>

// Função recursiva para calcular o número de Stirling do segundo tipo
int stirlingNumber(int n, int k) {
    // Condições de base
    if (n == 0 && k == 0) return 1;
    if (n == 0 || k == 0) return 0;
    
    // Recorrência: S(n, k) = k * S(n-1, k) + S(n-1, k-1)
    return k * stirlingNumber(n-1, k) + stirlingNumber(n-1, k-1);
}

int main() {
    int n, k;

    printf("Entre com o valor de n (elementos): ");
    scanf("%d", &n);
    printf("Entre com o valor de k (subconjuntos): ");
    scanf("%d", &k);

    printf("O número de Stirling do segundo tipo S(%d, %d) é %d\n", n, k, stirlingNumber(n, k));

    return 0;
}
