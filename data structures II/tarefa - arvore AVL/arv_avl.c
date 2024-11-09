/*
    Nome: Leonardo Cremasco Bernardes Boscariol
    Nome: Vitor Niels Flores Jensen
*/


#include <stdio.h>
#include <stdlib.h>

/*
    ***********************************************
    structs para criar os "nós" para colocar na árvore
    ***********************************************
*/

typedef struct Produto {
    int codigo;
    int qtd;
} Produto;


typedef struct Node {
    Produto product;
    int altura;
    struct Node *esq;
    struct Node *dir;
} Node;

/*
    ***********************************************
    funcoes auxiliares para criar e realizar rotações na arvore AVl
    ***********************************************
*/

int altura (Node *n){
    return n ? n-> altura : 0;
}

int max(int a, int b){
    return (a>b) ? a:b;
}

/*
    ***********************************************
    funcao para criar novo no p/ arvore
    ***********************************************
*/

Node* cria_node (int codigo, int qtd) {
    Node* node = (Node*)malloc (sizeof(Node)); // aloca de acordo com o node (nó)
    node->product.codigo = codigo;
    node->product.qtd = qtd;
    node->altura = 1; // 1 nivel de altura da arvore
    node->esq = node->dir = NULL; //como cria um novo nó, atribuímos nenhum node para os lados
    return node;  
}

/*
    ***********************************************
    funcao para criar rotações p/ arvore
    ***********************************************
*/

Node* rota_dir(Node *y) {
    Node *x = y->esq;
    Node *T2 = x->dir;

    y->dir = y;
    x->esq = T2;

    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

Node* rota_esq(Node *x) {
    Node *y = x->dir;
    Node *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

int balanceamento_avl(Node *n) {
    return n ? altura(n->esq) - altura(n->dir) : 0;
}

/*
    ***********************************************
    funcao p inserir nó na arvore avl
    ***********************************************
*/

Node* inserir(Node* node, int codigo, int qtd) {
    if (node == NULL)
        return cria_node(codigo, qtd);

    if (codigo < node->product.codigo)
        node->esq = inserir(node->esq, codigo, qtd);
    else if (codigo > node->product.codigo)
        node->dir = inserir(node->dir, codigo, qtd);
    else {
        node->product.qtd = qtd;
        return node;
    }

    node->altura = 1 + max(altura(node->esq), altura(node->dir));
    int balance = balanceamento_avl(node);

    if (balance > 1 && codigo < node->esq->product.codigo)
        return rota_dir(node);

    if (balance < -1 && codigo > node->dir->product.codigo)
        return rota_esq(node);

    if (balance > 1 && codigo > node->esq->product.codigo) {
        node->esq = rota_esq(node->esq);
        return rota_dir(node);
    }

    if (balance < -1 && codigo < node->dir->product.codigo) {
        node->dir = rota_dir(node->dir);
        return rota_esq(node);
    }

    return node;
}

/*
    ***********************************************
    funcao p encontrar menor valor para remover & remoção
    ***********************************************
*/

Node* menor_ValorNode(Node* node) {
    Node* atual = node;
    while (atual->esq != NULL)
        atual = atual->esq;
    return atual;
}


Node* remover(Node* root, int codigo) {
    if (root == NULL)
        return root;

    if (codigo < root->product.codigo)
        root->esq = remover(root->esq, codigo);
    else if (codigo > root->product.codigo)
        root->dir = remover(root->dir, codigo);
    else {
        if ((root->esq == NULL) || (root->dir == NULL)) {
            Node *temp = root->esq ? root->esq : root->dir;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            Node* temp = menor_ValorNode(root->dir);
            root->product = temp->product;
            root->dir = remover(root->dir, temp->product.codigo);
        }
    }

    if (root == NULL)
        return root;

    root->altura = 1 + max(altura(root->esq), altura(root->dir));
    int balance = balanceamento_avl(root);

    if (balance > 1 && balanceamento_avl(root->esq) >= 0)
        return rota_dir(root);

    if (balance > 1 && balanceamento_avl(root->esq) < 0) {
        root->esq = rota_esq(root->esq);
        return rota_dir(root);
    }

    if (balance < -1 && balanceamento_avl(root->dir) <= 0)
        return rota_esq(root);

    if (balance < -1 && balanceamento_avl(root->dir) > 0) {
        root->dir = rota_dir(root->dir);
        return rota_esq(root);
    }

    return root;
}

/*
    ***********************************************
    funcao p buscar um produto na arvore avl
    ***********************************************
*/

Node* buscar(Node* root, int codigo) {
    if (root == NULL || root->product.codigo == codigo)
        return root;
    if (codigo < root->product.codigo)
        return buscar(root->esq, codigo);
    return buscar(root->dir, codigo);
}

/*
    ***********************************************
    funcao p fazer uma lista dos produtos em ordem crescente
    ***********************************************
*/

void listarEmOrdem(Node* root) {
    if (root != NULL) {
        listarEmOrdem(root->esq);
        printf("Código: %d, qtd: %d\n", root->product.codigo, root->product.qtd);
        listarEmOrdem(root->dir);
    }
}

/*
    ***********************************************
    criação de um menu para criar as transações
    ***********************************************
*/

void menu() {
    Node* root = NULL;
    int opcao, codigo, qtd;
     
     do {
        printf("\nControle de Estoque - Arvore AVL\n");
        printf("1. Inserir produto\n");
        printf("2. Remover produto\n");
        printf("3. Buscar produto\n");
        printf("4. Listar produtos em ordem\n");
        printf("5. Sair\n");
        printf("Escolha uma opcão: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo);
                printf("Digite a qtd em estoque: ");
                scanf("%d", &qtd);
                root = inserir(root, codigo, qtd);
                printf("Produto inserido/atualizado com sucesso.\n");
                break;
            case 2:
                printf("Digite o codigo do produto a remover: ");
                scanf("%d", &codigo);
                root = remover(root, codigo);
                printf("Produto removido com sucesso.\n");
                break;
            case 3:
                printf("Digite o codigo do produto a buscar: ");
                scanf("%d", &codigo);
                Node* product = buscar(root, codigo);
                if (product)
                    printf("qtd em estoque: %d\n", product->product.qtd);
                else
                    printf("Produto nao encontrado.\n");
                break;
            case 4:
                printf("Lista de produtos:\n");
                listarEmOrdem(root);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 5);
}

int main() {
    menu();
    return 0;
}