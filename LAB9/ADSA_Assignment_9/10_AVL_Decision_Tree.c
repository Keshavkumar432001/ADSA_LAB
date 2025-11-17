// Q10. Write a program to implement AVL tree deletion, after each deletion print: 
//      A) Type of Rotation 
//      B) Height of the tree 
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    int height;
    struct Node *left, *right;
};
int max(int a, int b) { return (a > b) ? a : b; }
int height(struct Node *n) {
    return (n == NULL) ? 0 : n->height;
}
struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}
int getBF(struct Node *n) {
    return (n == NULL) ? 0 : height(n->left) - height(n->right);
}
struct Node* rightRotate(struct Node* y) {
    printf("Rotation: RIGHT ROTATION (LL case)\n");
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
struct Node* leftRotate(struct Node* x) {
    printf("Rotation: LEFT ROTATION (RR case)\n");
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
struct Node* getMinValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}
struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return createNode(key);
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
        node->left = leftRotate(node->left);
        printf("Rotation: LEFT-RIGHT ROTATION (LR case)\n");
        return rightRotate(node);
    }
    if (bf < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        printf("Rotation: RIGHT-LEFT ROTATION (RL case)\n");
        return leftRotate(node);
    }
    return node;
}
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }
        struct Node* temp = getMinValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    if (root == NULL) return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int bf = getBF(root);
    if (bf > 1 && getBF(root->left) >= 0)
        return rightRotate(root);
    if (bf > 1 && getBF(root->left) < 0) {
        root->left = leftRotate(root->left);
        printf("Rotation: LEFT-RIGHT ROTATION (LR case)\n");
        return rightRotate(root);
    }
    if (bf < -1 && getBF(root->right) <= 0)
        return leftRotate(root);
    if (bf < -1 && getBF(root->right) > 0) {
        root->right = rightRotate(root->right);
        printf("Rotation: RIGHT-LEFT ROTATION (RL case)\n");
        return leftRotate(root);
    }
    printf("Rotation: NONE\n");
    return root;
}
int main() {
    struct Node* root = NULL;
    int n, value;
    printf("How many values to insert? ");
    scanf("%d", &n);
    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    int delCount;
    printf("\nHow many values to delete? ");
    scanf("%d", &delCount);
    printf("Enter values to delete:\n");
    for (int i = 0; i < delCount; i++) {
        scanf("%d", &value);
        printf("\nDeleting %d...\n", value);
        root = deleteNode(root, value);
        printf("Height of tree after deletion: %d\n", height(root));
        printf("-------------------------------\n");
    }
    return 0;
}
