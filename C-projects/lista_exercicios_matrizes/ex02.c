// ex. 02

#include <stdio.h>

// Função para calcular o valor da atualização do título
float calculusUpdate(float multa, float inpc[], int numMeses) {
    float atualizacao = multa;
    int i;
    
    for (i = 0; i < numMeses; i++) {
        atualizacao += inpc[i];
        multa *= inpc[i];
    }
    
    atualizacao += multa;
    
    return atualizacao;
}

int main() {
    float fatura = 100.0; // valor da fatura
    float multa = 0.02; // valor da multa fixa
    float inpc[] = {0.012, 0.012, 0.012, 0.012, 0.012, 0.012}; // índices do (INPC) de janeiro a junho
    int numMeses = sizeof(inpc) / sizeof(inpc[0]);
    int i;
    
    printf("Tabela de atualizacao dos titulos\n\n");
    
    for (i = 0; i < numMeses; i++) {
        float atualizacao = calculusUpdate(multa, inpc, i);
        float valorPagar = fatura + atualizacao;
        
        printf("vencimento em 10/%02d - Pagamento em 14/%02d\n", i+1, i+1);
        printf("valor do titulo: %.2f\n", fatura);
        printf("indice de atualizacao: %.3f%%\n", atualizacao * 100);
        printf("valor da atualizacao: %.3f\n", atualizacao);
        printf("valor a pagar: %.2f\n\n", valorPagar);
    }
    
    return 0;
}

