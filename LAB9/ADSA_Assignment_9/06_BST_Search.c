// Given a BST, write functions to find: 
// A) k-th smallest element 
// B) k-th largest element 
// (Without storing traversal in an array) 
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
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
void kthSmallest(struct Node* root, int k, int *count, int *result) {
    if (root == NULL || *result != -1) return;
    kthSmallest(root->left, k, count, result);
    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }
    kthSmallest(root->right, k, count, result);
}
void kthLargest(struct Node* root, int k, int *count, int *result) {
    if (root == NULL || *result != -1) return;
    kthLargest(root->right, k, count, result);
    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }
    kthLargest(root->left, k, count, result);
}
int main() {
    struct Node* root = NULL;
    int n, value, k;
    printf("How many nodes? ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("Enter k: ");
    scanf("%d", &k);
    int count = 0, result = -1;
    
    kthSmallest(root, k, &count, &result);
    if (result != -1)
        printf("K-th Smallest = %d\n", result);
    else
        printf("Invalid k\n");

    count = 0; 
    result = -1;

    kthLargest(root, k, &count, &result);
    if (result != -1)
        printf("K-th Largest = %d\n", result);
    else
        printf("Invalid k\n");
    return 0;
}
