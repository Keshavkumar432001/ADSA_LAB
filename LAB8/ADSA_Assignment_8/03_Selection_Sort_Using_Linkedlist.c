// Q3. Implement selection sort on a singly linked list using node swaps.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void swapNodes(struct Node** head_ref, struct Node* node1, struct Node* node2) {
    if (node1 == node2) return;
    struct Node *prev1 = NULL, *prev2 = NULL, *curr = *head_ref;
    while (curr && curr->next) {
        if (curr->next == node1)
            prev1 = curr;
        if (curr->next == node2)
            prev2 = curr;
        curr = curr->next;
    }
    if (node1 == NULL || node2 == NULL)
        return;
    if (prev1)
        prev1->next = node2;
    else
        *head_ref = node2;
    if (prev2)
        prev2->next = node1;
    else
        *head_ref = node1;
    struct Node* temp = node2->next;
    node2->next = node1->next;
    node1->next = temp;
}
void selectionSortLinkedList(struct Node** head_ref) {
    struct Node* start = *head_ref;
    int iteration = 1;
    while (start) {
        struct Node* minNode = start;
        struct Node* r = start->next;
        while (r) {
            if (r->data < minNode->data)
                minNode = r;
            r = r->next;
        }
        if (minNode != start) {
            swapNodes(head_ref, start, minNode);
            struct Node* temp = start;
            start = minNode;
            minNode = temp;
        }
        printf("Iteration %d: ", iteration++);
        struct Node* temp = *head_ref;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
        start = start->next;
    }
}
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(struct Node* node) {
    while (node) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 22);
    push(&head, 12);
    push(&head, 25);
    push(&head, 64);
    printf("Original linked list: ");
    printList(head);
    selectionSortLinkedList(&head);
    printf("\nSorted linked list: ");
    printList(head);
    return 0;
}
