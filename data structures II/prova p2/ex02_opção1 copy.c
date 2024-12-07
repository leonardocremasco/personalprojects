#include <stdio.h>
#include <stdlib.h>

// definição do nó da ABB (struct)
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// funcao (struct) para criar um nó
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// função para inserir um nó na ABB desejada
Node* insert(Node* root, int key) {
    if (root == NULL) return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// função que insere todos os nós de uma árvore na outra
void mergeTrees(Node* root1, Node* root2) {
    if (root2 == NULL) return;
    mergeTrees(root1, root2->left);
    root1 = insert(root1, root2->key);
    mergeTrees(root1, root2->right);
}

// função para imprimir em ordem uma ABB
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->key);
    inorderTraversal(root->right);
}

// exemplo de uso
int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;

    // ABB 1
    root1 = insert(root1, 10);
    root1 = insert(root1, 5);
    root1 = insert(root1, 15);

    // ABB 2
    root2 = insert(root2, 12);
    root2 = insert(root2, 7);
    root2 = insert(root2, 20);

    printf("ABB 1 (antes da juncao): ");
    inorderTraversal(root1);
    printf("\nABB 2: ");
    inorderTraversal(root2);

    // Fusao das ABBs
    mergeTrees(root1, root2);

    printf("\nABB 1 (depois da juncao): ");
    inorderTraversal(root1);

    return 0;
}
