//  ex. 2

#include <stdio.h>

void menuDepartamentos();
void menuRH();
void menuFinanceiro();
void menuContabilidade();
void menuContratos();
void menuPonto();
void menuAdmissao();
void menuDemissao();
void menuDigitalizacao();

int main() {
    menuDepartamentos(); // Iniciar no menu de departamentos
    return 0;
}

void menuDepartamentos() {
    int opcao;
    printf("---------- DEPARTAMENTOS ----------\n");
    printf("1. RH\n");
    printf("2. FINANCEIRO\n");
    printf("3. CONTABILIDADE\n");
    printf("0. SAIR\n");
    printf("Escolha o departamento: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            menuRH();
            break;
        case 2:
            menuFinanceiro();
            break;
        case 3:
            menuContabilidade();
            break;
        case 0:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("Opcao invalida.\n");
            menuDepartamentos();
            break;
    }
}

void menuRH() {
    int opcao;
    printf("---------- RH ----------\n");
    printf("1. CONTRATOS\n");
    printf("2. PONTO\n");
    printf("0. VOLTAR\n");
    printf("Escolha a opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            menuContratos();
            break;
        case 2:
            menuPonto();
            break;
        case 0:
            menuDepartamentos();
            break;
        default:
            printf("Opção invalida.\n");
            menuRH();
            break;
    }
}

void menuFinanceiro() {
    printf("---------- FINANCEIRO ----------\n");
    // ImplementaA as opções do menu financeiro aqui
    menuDepartamentos(); // Voltar ao menu de departamentos
}

void menuContabilidade() {
    printf("---------- CONTABILIDADE ----------\n");
    // ImplementaA as opções do menu de contabilidade aqui
    menuDepartamentos(); // Voltar ao menu de departamentos
}

void menuContratos() {
    printf("---------- CONTRATOS ----------\n");
    // ImplementaA as opções do menu de contratos aqui
    menuRH(); // Voltar ao menu RH
}

void menuPonto() {
    printf("---------- PONTO ----------\n");
    // Implementar as opções do menu de ponto aqui
    menuRH(); // Voltar ao menu RH
}

void menuAdmissao() {
    printf("---------- ADMISSAO ----------\n");
    // Implementa as opções do menu de admissão aqui
    menuContratos(); // Voltar ao menu de contratos
}

void menuDemissao() {
    printf("---------- DEMISSAO ----------\n");
    // ImplementaA as opções do menu de demissão aqui
    menuContratos(); // Voltar ao menu de contratos
}

void menuDigitalizacao() {
    printf("---------- DIGITALIZACAO DE DOCUMENTOS ----------\n");
    // Implementa as opções do menu de digitalização de documentos aqui
    menuContratos(); // Voltar ao menu de contratos
}
