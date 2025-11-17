// Q3. Given any binary tree, write a program to verify whether it satisfies BST properties using the min–max recursive method. 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int isBST(struct Node* root, int min, int max) {
    if (root == NULL)
        return 1;
    if (root->data < min || root->data > max)
        return 0;
    return ( isBST(root->left, min, root->data - 1) &&
             isBST(root->right, root->data + 1, max) );
}
int main() {
    struct Node *root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(6);
    root->right->right = createNode(14);

    if (isBST(root, INT_MIN, INT_MAX))
        printf("The tree IS a BST\n");
    else
        printf("The tree is NOT a BST\n");
    return 0;
}
