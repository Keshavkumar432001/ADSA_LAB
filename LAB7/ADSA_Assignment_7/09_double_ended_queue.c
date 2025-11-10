// Q9. Implement a double-ended queue (deque) using a circular array with insert and delete operations at both ends.
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct Deque {
    int front, rear;
    int items[MAX];
};
struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = -1;
    deque->rear = -1;
    return deque;
}
int isFull(struct Deque* deque) {
    return (deque->front == 0 && deque->rear == MAX - 1) || (deque->front == deque->rear + 1);
}
int isEmpty(struct Deque* deque) {
    return deque->front == -1;
}
void insertFront(struct Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Deque overflow\n");
        return;
    }
    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX - 1;
    } else {
        deque->front--;
    }
    deque->items[deque->front] = data;
    printf("%d inserted at front\n", data);
}
void insertRear(struct Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Deque overflow\n");
        return;
    }
    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else if (deque->rear == MAX - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }
    deque->items[deque->rear] = data;
    printf("%d inserted at rear\n", data);
}
int deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque underflow\n");
        return -1;
    }
    int deletedData = deque->items[deque->front];
    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else if (deque->front == MAX - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }
    printf("%d deleted from front\n", deletedData);
    return deletedData;
}
int deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque underflow\n");
        return -1;
    }
    int deletedData = deque->items[deque->rear];
    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = MAX - 1;
    } else {
        deque->rear--;
    }
    printf("%d deleted from rear\n", deletedData);
    return deletedData;
}
void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = deque->front;
    while (1) {
        printf("%d ", deque->items[i]);
        if (i == deque->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    struct Deque* deque = createDeque();
    insertRear(deque, 10);
    insertRear(deque, 20);
    insertFront(deque, 5);
    display(deque);
    deleteFront(deque);
    display(deque);
    deleteRear(deque);
    display(deque);
    insertFront(deque, 15);
    insertRear(deque, 25);
    insertRear(deque, 30);
    display(deque);
    return 0;
}