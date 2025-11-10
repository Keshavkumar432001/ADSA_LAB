// Q10. Write a program using both stack and queue to check whether a given string is a palindrome.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct Stack {
    int top;
    char items[MAX];
};
struct Queue {
    int front, rear;
    char items[MAX];
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}
int isStackEmpty(struct Stack* stack) {
    return stack->top == -1;
}
int isQueueEmpty(struct Queue* queue) {
    return queue->front == -1 || queue->front > queue->rear;
}
void push(struct Stack* stack, char item) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}
char pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}
void enqueue(struct Queue* queue, char item) {
    if (queue->rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->items[++queue->rear] = item;
}
char dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue underflow\n");
        return '\0';
    }
    return queue->items[queue->front++];
}
int isPalindrome(const char* str) {
    struct Stack* stack = createStack();
    struct Queue* queue = createQueue();
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        push(stack, str[i]);
        enqueue(queue, str[i]);
    }
    for (int i = 0; i < n; i++) {
        if (pop(stack) != dequeue(queue)) {
            free(stack);
            free(queue);
            return 0; 
        }
    }
    free(stack);
    free(queue);
    return 1; 
}
int main() {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = 0; 
    if (isPalindrome(str)) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }
    return 0;
}
