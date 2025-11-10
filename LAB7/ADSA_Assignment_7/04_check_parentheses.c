// Q4. Write a program to check balanced parentheses in an expression using a stack implemented with a linked list. 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct StackNode {
    char data;
    struct StackNode* next;
};
struct Stack {
    struct StackNode* top;
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}
bool isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}
void push(struct Stack* stack, char data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    struct StackNode* temp = stack->top;
    char poppedData = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedData;
}
bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}
bool areParenthesesBalanced(const char* expr) {
    struct Stack* stack = createStack();
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(stack, expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (isEmpty(stack)) {
                free(stack);
                return false;
            }
            char topChar = pop(stack);
            if (!isMatchingPair(topChar, expr[i])) {
                free(stack);
                return false;
            }
        }
    }
    bool balanced = isEmpty(stack);
    free(stack);
    return balanced;
}
int main() {
    const char* expr = "{[()]}";
    if (areParenthesesBalanced(expr)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
    return 0;
}
