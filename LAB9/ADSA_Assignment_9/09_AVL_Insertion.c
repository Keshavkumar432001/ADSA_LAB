//Q9.Implement AVL Tree insertion, after each insertion display: 
//   A) Balance Factor 
//   B) Rotation Performed 
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    int height;
    struct Node *left, *right;
};
int max(int a, int b) { return (a > b) ? a : b; }
int height(struct Node *n) {
    if (n == NULL) return 0;
    return n->height;
}
struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}
int getBF(struct Node *n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}
struct Node* rightRotate(struct Node* y) {
    printf("Rotation Performed: RIGHT ROTATION (LL case)\n");
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}
struct Node* leftRotate(struct Node* x) {
    printf("Rotation Performed: LEFT ROTATION (RR case)\n");
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}
struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int bf = getBF(node);

    if (bf > 1 && key < node->left->data)
        return rightRotate(node);

    if (bf < -1 && key > node->right->data)
        return leftRotate(node);

    if (bf > 1 && key > node->left->data) {
        printf("Rotation Performed: LEFT-RIGHT ROTATION (LR case)\n");
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (bf < -1 && key < node->right->data) {
        printf("Rotation Performed: RIGHT-LEFT ROTATION (RL case)\n");
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    printf("Rotation Performed: NONE\n");
    return node;
}
void printBF(struct Node* root) {
    if (root == NULL) return;
    printf("Node %d -> BF = %d\n", root->data, getBF(root));
    printBF(root->left);
    printBF(root->right);
}
int main() {
    struct Node* root = NULL;
    int n, value;
    printf("How many values to insert? ");
    scanf("%d", &n);
    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        printf("\nInserting %d...\n", value);
        root = insert(root, value);
        printf("Balance Factors after insertion:\n");
        printBF(root);
        printf("------------------------------\n");
    }
    return 0;
}
