//Ex06) Cadastro de Produtos

#include <stdio.h>
#include <stdlib.h>

// Definindo a struct Produto
struct Produto {
    int codigo;
    char nome[50];
    float preco;
};

// Protótipos das funções
void cadastrarProduto();
void exibirProdutos();

int main() {
    int escolha;

    do {
        // Menu principal
        printf("\nMenu:\n");
        printf("1. Cadastrar novo produto\n");
        printf("2. Exibir todos os produtos cadastrados\n");
        printf("3. Sair\n");
        printf("Escolha a opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                exibirProdutos();
                break;
            case 3:
                printf("Saindo do programa. Adeus!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (escolha != 3);

    return 0;
}

void cadastrarProduto() {
    struct Produto produto;

    // Solicitando informações do usuário
    printf("\nDigite o codigo do produto: ");
    scanf("%d", &produto.codigo);
    printf("Digite o nome do produto: ");
    scanf("%s", produto.nome);
    printf("Digite o preco do produto: ");
    scanf("%f", &produto.preco);

    // Abrindo o arquivo para escrita
    FILE *arquivo = fopen("produtos.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    // Escrevendo as informações no arquivo
    fprintf(arquivo, "%d %s %.2f\n", produto.codigo, produto.nome, produto.preco);

    // Fechando o arquivo
    fclose(arquivo);

    printf("Produto cadastrado com sucesso!\n");
}

void exibirProdutos() {
    struct Produto produto;

    // Abrindo o arquivo para leitura
    FILE *arquivo = fopen("produtos.txt", "r");

    if (arquivo == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    // Lendo e exibindo as informações dos produtos
    printf("\nProdutos cadastrados:\n");
    while (fscanf(arquivo, "%d %s %f", &produto.codigo, produto.nome, &produto.preco) != EOF) {
        printf("Codigo: %d, Nome: %s, Preco: %.2f\n", produto.codigo, produto.nome, produto.preco);
    }

    // Fechando o arquivo
    fclose(arquivo);
}

