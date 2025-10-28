// Q2. Write a program to search for a given element in a linked list and print its position. 
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
int searchElement(int key) {
    struct Node* current = head;
    int position = 0;
    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; 
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
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    printf("Linked List:\n");
    printList();
    int key = 30;
    int position = searchElement(key);
    if (position != -1) {
        printf("Element %d found at position: %d\n", key, position);
    } else {
        printf("Element %d not found in the list.\n", key);
    }
    return 0;
}