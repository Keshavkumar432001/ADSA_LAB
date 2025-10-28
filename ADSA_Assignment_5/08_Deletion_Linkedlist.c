// Q8. Delete nodes from a singly linked list from:The beginning, The end and A given position.
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
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (position == 0) {
        deleteFromBeginning();
        return;
    }
    struct Node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp->next == NULL) {
            printf("Position out of bounds. Nothing to delete.\n");
            return;
        }
        temp = temp->next;
    }
    struct Node* nodeToDelete = temp->next;
    if (nodeToDelete == NULL) {
        printf("Position out of bounds. Nothing to delete.\n");
        return;
    }
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
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
    printf("Initial Linked List:\n");
    printList();
    deleteFromBeginning();
    printf("Linked List after deleting from the beginning:\n");
    printList();
    deleteFromEnd();
    printf("Linked List after deleting from the end:\n");
    printList();
    deleteFromPosition(1);
    printf("Linked List after deleting from position 1:\n");
    printList();
    return 0;
}
