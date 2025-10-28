// Q10. Remove duplicate elements from a sorted linked list so that each element appears only once.
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
void removeDuplicates() {
    struct Node* current = head;
    struct Node* nextNext;
    if (current == NULL) return;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        } 
        else {
            current = current->next;
        }
    }
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
    head->next = createNode(10);
    head->next->next = createNode(20);
    head->next->next->next = createNode(30);
    head->next->next->next->next = createNode(30);
    head->next->next->next->next->next = createNode(40);
    head->next->next->next->next->next->next = createNode(50);
    head->next->next->next->next->next->next->next = createNode(50);
    printf("Original Linked List:\n");
    printList();
    removeDuplicates();
    printf("Linked List after removing duplicates:\n");
    printList();
    return 0;
}
