// Q7. Implement a circular queue using an array and perform enqueue, dequeue, and display operations demonstrating wrap-around behavior.
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct CircularQueue {
    int front, rear;
    int items[MAX];
};
struct CircularQueue* createCircularQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}
int isFull(struct CircularQueue* queue) {
    return (queue->rear + 1) % MAX == queue->front;
}
int isEmpty(struct CircularQueue* queue) {
    return queue->front == -1;
}
void enqueue(struct CircularQueue* queue, int data) {
    if (isFull(queue)) {
        printf("Circular Queue overflow\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->items[queue->rear] = data;
    printf("%d enqueued to circular queue\n", data);
}
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue underflow\n");
        return -1;
    }
    int dequeuedData = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    return dequeuedData;
}
void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = queue->front;
    while (1) {
        printf("%d ", queue->items[i]);
        if (i == queue->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    struct CircularQueue* queue = createCircularQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    display(queue);
    printf("%d dequeued from circular queue\n", dequeue(queue));
    printf("%d dequeued from circular queue\n", dequeue(queue));
    display(queue);
    enqueue(queue, 60);
    enqueue(queue, 70);
    display(queue);
    return 0;
}