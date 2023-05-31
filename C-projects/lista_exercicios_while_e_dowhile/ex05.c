// ex. 5

#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
    int opcao;

    do {
        printf("Menu:\n");
        printf("\n");
        printf("1) Opcao 1\n");
        printf("2) Opcao 2\n");
        printf("3) Opcao 3\n");
        printf("4) Opcao 4\n");
        printf("5) Opcao 5\n");
        printf("0) Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Saindo do programa...\n");
                break;
            case 1:
                printf("Você escolheu a opcao 1.\n");
                // Coloque aqui o código correspondente à opção 1
                break;
            case 2:
                printf("Você escolheu a opcao 2.\n");
                // Coloque aqui o código correspondente à opção 2
                break;
            case 3:
                printf("Você escolheu a opcao 3.\n");
                // Coloque aqui o código correspondente à opção 3
                break;
            case 4:
                printf("Você escolheu a opcao 4.\n");
                // Coloque aqui o código correspondente à opção 4
                break;
            case 5:
                printf("Você escolheu a opcao 5.\n");
                // Coloque aqui o código correspondente à opção 5
                break;
            default:
                printf("Opcao invalida. Por favor, digite uma opcao valida.\n");
                break;
        }

        printf("\n");

    } while (opcao != 0);

    return 0;
}
