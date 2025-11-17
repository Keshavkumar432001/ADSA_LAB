// Q7.Given a sorted array, build a balanced BST using divide-and-conquer.Print level-order traversal of the new tree. 
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
struct Node* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    struct Node* root = createNode(arr[mid]);
    root->left  = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}
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
int isEmpty() {
    return front == -1;
}
void levelOrder(struct Node* root) {
    if (root == NULL) return;
    enqueue(root);
    while (!isEmpty()) {
        struct Node* current = dequeue();
        printf("%d ", current->data);
        if (current->left) enqueue(current->left);
        if (current->right) enqueue(current->right);
    }
}
int main() {
    int n;
    printf("Enter size of sorted array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted values:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = sortedArrayToBST(arr, 0, n - 1);

    printf("Level-order traversal of Balanced BST:\n");
    levelOrder(root);
    return 0;
}
