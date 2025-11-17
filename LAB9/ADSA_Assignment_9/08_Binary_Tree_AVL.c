// Q8.Given a binary tree, write a program to check whether it is height-balanced (AVL property).Also print the balance factor of each node. 
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int height(struct Node* root) {
    if (root == NULL) return 0;
    
    int lh = height(root->left);
    int rh = height(root->right);

    return (lh > rh ? lh : rh) + 1;
}
void printBalanceFactors(struct Node* root) {
    if (root == NULL) return;

    int lh = height(root->left);
    int rh = height(root->right);
    int bf = lh - rh;
    printf("Node %d -> BF = %d\n", root->data, bf);
    printBalanceFactors(root->left);
    printBalanceFactors(root->right);
}
int isBalanced(struct Node* root) {
    if (root == NULL) return 1;

    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1)
        return 0; 
    return isBalanced(root->left) && isBalanced(root->right);
}
int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    printf("Balance Factors of Each Node:\n");
    printBalanceFactors(root);
    if (isBalanced(root))
        printf("\nThe tree IS height-balanced.\n");
    else
        printf("\nThe tree is NOT height-balanced.\n");

    return 0;
}