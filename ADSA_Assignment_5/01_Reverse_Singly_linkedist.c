// Q1. Write a program to reverse a singly linked list (implement both iterative and recursive methods).
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Iterative method to reverse the linked list
void reverseIt() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;
    }
    head = prev;
}
// Recursive method to reverse the linked list
struct Node* reverseRecUtil(struct Node* current, struct Node* prev) {
    if (current == NULL) {
        return prev;
    }
    struct Node* next = current->next;
    current->next = prev;
    return reverseRecUtil(next, current);
}
void reverseRec() {
    head = reverseRecUtil(head, NULL);
}
void printList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    printf("Original Linked List:\n");
    printList();
    reverseIt();
    printf("Reversed Linked List (Iterative):\n");
    printList();
    reverseRec();
    printf("Reversed Linked List (Recursive):\n");
    printList();
    return 0;
}