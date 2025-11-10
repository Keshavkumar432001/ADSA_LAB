// Q7. Implement a stack-based simulation of the merge process where push and pop operations are used instead of recursion.
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
    int items[MAX];
    int top;
} Stack;
void initStack(Stack* s) {
    s->top = -1;
}
int isFull(Stack* s) {
    return s->top == MAX - 1;
}
int isEmpty(Stack* s) {
    return s->top == -1;
}
void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++s->top] = value;
}
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->items[s->top--];
}
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
    free(L);
    free(R);
}
void stackBasedMergeSort(int arr[], int n) {
    Stack s;
    initStack(&s);
    push(&s, 0);
    push(&s, n - 1);
    while (!isEmpty(&s)) {
        int right = pop(&s);
        int left = pop(&s);
        if (left < right) {
            int mid = left + (right - left) / 2;
            push(&s, left);
            push(&s, mid);
            push(&s, mid + 1);
            push(&s, right);
            merge(arr, left, mid, right);
        }
    }
}
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    stackBasedMergeSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
