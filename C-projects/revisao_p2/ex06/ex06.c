//Ex06) Cadastro de Produtos

#include <stdio.h>
#include <stdlib.h>

// struct Produto
struct Produto {
    int codigo;
    char nome[50];
    float preco;
};

// cadastrar um novo produto
void cadastrarProduto() {
    struct Produto novoProduto;

    printf("Digite o codigo do produto: ");
    scanf("%d", &novoProduto.codigo);

    printf("Digite o nome do produto: ");
    scanf("%s", novoProduto.nome);

    printf("Digite o preco do produto: ");
    scanf("%f", &novoProduto.preco);

    //arquivo para escrita (modo "a" para adicionar ao final do arquivo)
    FILE *arquivo = fopen("produtos.txt", "a");

    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Escrever as informações do produto no arquivo
    fprintf(arquivo, "%d %s %.2f\n", novoProduto.codigo, novoProduto.nome, novoProduto.preco);

    // Fechar o arquivo
    fclose(arquivo);

    printf("Produto cadastrado com sucesso!\n");
}

// Função para exibir todos os produtos cadastrados
void exibirProdutos() {
    // Abrir o arquivo para leitura
    FILE *arquivo = fopen("produtos.txt", "r");

    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Nenhum produto cadastrado ainda.\n");
        return;
    }

    struct Produto produtoLido;

    // Ler e exibir cada produto do arquivo
    while (fscanf(arquivo, "%d %s %f", &produtoLido.codigo, produtoLido.nome, &produtoLido.preco) != EOF) {
        printf("Código: %d, Nome: %s, Preço: %.2f\n", produtoLido.codigo, produtoLido.nome, produtoLido.preco);
    }

    // Fechar o arquivo
    fclose(arquivo);
}

int main() {
    int escolha;

    do {
        // Menu de opções
        printf("\nMenu:\n");
        printf("1. Cadastrar novo produto\n");
        printf("2. Exibir todos os produtos cadastrados\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                exibirProdutos();
                break;
            case 3:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (escolha != 3);

    return 0;
}
