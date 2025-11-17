// Q4.Perform level-order (breadth-first) traversal of a binary tree using a queue. 
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
struct Queue {
    struct Node* arr[100];
    int front, rear;
};
void initQueue(struct Queue *q) {
    q->front = q->rear = -1;
}
int isEmpty(struct Queue *q) {
    return (q->front == -1);
}
void enqueue(struct Queue *q, struct Node* node) {
    if (q->rear == 99) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}
struct Node* dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        return NULL;
    }
    struct Node* temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return temp;
}
void levelOrder(struct Node* root) {
    if (root == NULL) return;
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        struct Node* current = dequeue(&q);
        printf("%d ", current->data);

        if (current->left)
            enqueue(&q, current->left);
        if (current->right)
            enqueue(&q, current->right);
    }
}
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Level-order traversal: ");
    levelOrder(root);
    return 0;
}
