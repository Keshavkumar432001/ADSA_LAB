// Q1.Write a program to construct a binary tree using user input (level-order insertion).Perform preorder, inorder, and postorder traversals. 
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* queue[100];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}
struct Node* dequeue() {
    if (front == -1) return NULL;
    struct Node* temp = queue[front];
    
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return temp;
}
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insertLevelOrder(struct Node* root, int data) {
    struct Node* newNode = createNode(data);
    if (root == NULL)
        return newNode;
    front = rear = -1;
    enqueue(root);

    while (front != -1) {
        struct Node* temp = dequeue();

        if (temp->left == NULL) {
            temp->left = newNode;
            return root;
        } else {
            enqueue(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        } else {
            enqueue(temp->right);
        }
    }
    return root;
}
void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertLevelOrder(root, value);
    }
    printf("\nPreorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\n");
    return 0;
}
