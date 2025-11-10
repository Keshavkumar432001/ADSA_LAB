// Q3. Write a program to reverse a string using a stack implemented with an array.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct Stack {
    int top;
    char items[MAX];
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}
void reverseString(char* str) {
    struct Stack* stack = createStack();
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        push(stack, str[i]);
    }
    for (int i = 0; i < n; i++) {
        str[i] = pop(stack);
    }
    free(stack);
}
int main() {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = 0;
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}