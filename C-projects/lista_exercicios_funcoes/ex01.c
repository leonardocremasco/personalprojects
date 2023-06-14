// Ex. 1

#include <stdio.h>
#include <stdbool.h>

int main () {

    int op_atendence, n_carteirinha;

    printf("----------------------------------------\n");
    printf("   AUTO ATENDIMENTO SANTA CASA SAUDE      \n");
    printf("----------------------------------------\n");
    printf("\n");

    printf("Digite o numero da opcao de atendimento [1], [2], [3], [8], [9]: \n");
    printf("\n");
    printf("[1] Auditoria medica \n");
    printf("[2] 2a via de boletos \n");
    printf("[3] Seus agendamentos medicos \n");
    printf("[5] Informe de rendimentos (Decl.Imp.Renda) \n");
    printf("[8] Nao receber mensagens automaticas neste celular \n");
    printf("[9] Conversar com nossos atendentes \n");
    printf("\n");
    printf("Opcao escolhida: ");
    scanf("%d", &op_atendence);

    switch (op_atendence) {
   
    case 1:
        printf("Voce solicitou a opcao ([1] Auditoria medica), logo, segue abaixo sua auditoria medica: ");
        break;
    
    case 2:
        printf("Voce solicitou a opcao ([2] 2a via de boletos), logo, digite o numero da sua carteirinha (sem pontos e tracos, se desejar):");
        scanf("%d", &n_carteirinha);
        printf("copie o link no seu navegador  http://applicationspools.santacasadepiracicaba.com.br/downloads/BOL_02634052023.PDFSegue a linha digitavel do código de barras caso deseje copiar e colar para pagamento03399.84221 15000.000198 24709.501043 8 93460000037035");
        break;

    case 3:
        printf("Voce solicitou a opcao ([3] Seus agendamentos medicos), logo, digite seu cpf e numero da carteirinha (sem pontos e tracos, se desejar): ");
        break;

    case 5:
        printf("Voce solicitou a opcao ([5] Informe os rendimentos (Rend.Imp.Renda)), logo, faremos seu Rendimento de Imposto de Renda... ");
        break;

    case 8:
        printf("Voce solicitou a opcao ([8] Nao reveber mensagens automaticas nesse celular), logo, pararemos de enviar mensagens automaticas neste numero de celular. Obrigado! ");
        break;

    case 9:
        printf("Voce solicitou a opcao ([9] Conversar com nossos atendentes), logo, te encaminharemos para falar com nossos atendentes. ");
        break;

    default:
        printf("Desculpe, mas essa não é uma das opcoes possiveis de atendimento. ");
        break;
    }

    return 0;

}   