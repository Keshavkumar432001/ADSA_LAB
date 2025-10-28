// Q5. Implement insertion operations in a singly linked list to insert a node: At the beginning, At the end and At a given position.
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
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAtPosition(int data, int position) {
    if (position == 0) {
        insertAtBeginning(data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds. Inserting at the end instead.\n");
            insertAtEnd(data);
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
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
    insertAtEnd(20);
    insertAtEnd(30);
    printf("Linked List after inserting 20 and 30 at the end:\n");
    printList();
    insertAtBeginning(10);
    printf("Linked List after inserting 10 at the beginning:\n");
    printList();
    insertAtPosition(25, 2);
    printf("Linked List after inserting 25 at position 2:\n");
    printList();
    insertAtPosition(5, 0);
    printf("Linked List after inserting 5 at position 0:\n");
    printList();
    insertAtPosition(40, 10); // Position out of bounds
    printf("Linked List after attempting to insert 40 at out of bounds position 10:\n");
    printList();
    return 0;
}