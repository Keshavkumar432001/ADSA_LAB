// Q5. Implement a queue using an array and perform enqueue, dequeue, and display operations with overflow and underflow checks. 
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Queue {
    int front, rear;
    int items[MAX];
};
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}
int isFull(struct Queue* queue) {
    return queue->rear == MAX - 1;
}
int isEmpty(struct Queue* queue) {
    return queue->front == -1 || queue->front > queue->rear;
}
void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->items[++queue->rear] = data;
    printf("%d enqueued to queue\n", data);
}
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return -1;
    }
    return queue->items[queue->front++];
}
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}
int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    printf("%d dequeued from queue\n", dequeue(queue));
    display(queue);
    return 0;
}