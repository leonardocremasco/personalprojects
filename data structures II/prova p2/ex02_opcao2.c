#include <stdio.h>
#include <stdlib.h>

// definição do nó da ABB (struct)
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// função que cria um novo nó
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// função para converter uma ABB em um array ordenado (lista ordenada)
void treeToArray(Node* root, int* arr, int* index) {
    if (root == NULL) return;
    treeToArray(root->left, arr, index);
    arr[(*index)++] = root->key;
    treeToArray(root->right, arr, index);
}

// função para intercalar duas listas ordenadas em uma única lista ordenada
void mergeArrays(int* arr1, int size1, int* arr2, int size2, int* merged, int* mergedSize) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }
    while (i < size1) merged[k++] = arr1[i++];
    while (j < size2) merged[k++] = arr2[j++];
    *mergedSize = k; // Define o tamanho do array final
}

// função para construir uma ABB balanceada a partir de uma lista ordenada
Node* sortedArrayToBST(int* arr, int start, int end) {
    if (start > end) return NULL;

    int mid = (start + end) / 2;
    Node* root = newNode(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

// função para imprimir os elementos da ABB em ordem
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->key);
    inorderTraversal(root->right);
}

// função para inserir um elemento na ABB
Node* insert(Node* root, int key) {
    if (root == NULL) return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
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

    // converter ABBs para arrays (listas)
    int arr1[100], arr2[100], merged[200];
    int size1 = 0, size2 = 0, mergedSize = 0;

    treeToArray(root1, arr1, &size1);
    treeToArray(root2, arr2, &size2);

    // intercalando os arrays
    mergeArrays(arr1, size1, arr2, size2, merged, &mergedSize);

    // construindo uma ABB balanceada a partir do array intercalado
    Node* mergedRoot = sortedArrayToBST(merged, 0, mergedSize - 1);

    // imprimir a ABB resultante
    printf("ABB combinada e balanceada: ");
    inorderTraversal(mergedRoot);

    return 0;
}
