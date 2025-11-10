// Q5. Implement a merge procedure using two queues (each containing sorted integers) and output a single sorted queue.
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue* q) {
    return q->front == -1;
}
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->items[++q->rear] = value;
}
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}
void mergeQueues(Queue* q1, Queue* q2, Queue* merged) {
    while (!isEmpty(q1) && !isEmpty(q2)) {
        if (q1->items[q1->front] < q2->items[q2->front]) {
            enqueue(merged, dequeue(q1));
        } else {
            enqueue(merged, dequeue(q2));
        }
    }
    while (!isEmpty(q1)) {
        enqueue(merged, dequeue(q1));
    }
    while (!isEmpty(q2)) {
        enqueue(merged, dequeue(q2));
    }
}
void printQueue(Queue* q) {
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}
int main() {
    Queue q1, q2, merged;
    initQueue(&q1);
    initQueue(&q2);
    initQueue(&merged);
    enqueue(&q1, 10);
    enqueue(&q1, 30);
    enqueue(&q1, 50);

    enqueue(&q2, 20);
    enqueue(&q2, 40);
    enqueue(&q2, 60);
    printf("Queue 1: ");
    printQueue(&q1);
    printf("Queue 2: ");
    printQueue(&q2);
    mergeQueues(&q1, &q2, &merged);
    printf("Merged Queue: ");
    printQueue(&merged);
    return 0;
} 