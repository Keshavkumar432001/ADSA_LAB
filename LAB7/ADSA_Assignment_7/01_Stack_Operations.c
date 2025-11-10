// Q1. Implement a stack using an array and perform push, pop, display, and check stack overflow/underflow conditions.
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;
void initStack(Stack* stack) {
    stack->top = -1;
}
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        stack->arr[++stack->top] = value;
        printf("Pushed %d to stack\n", value);
    }
}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1; // Indicating stack is empty
    } else {
        return stack->arr[stack->top--];
    }
}
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}
int main() {
    Stack stack;
    initStack(&stack);
    int choice, value;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped %d from stack\n", value);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
} 