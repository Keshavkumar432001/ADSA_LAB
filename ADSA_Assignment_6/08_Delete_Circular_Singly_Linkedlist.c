// Q8.Write a function to delete a node with a specific value from a circular linked list.
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
void deleteNode(int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *current = head, *prev = NULL;
    if (current->data == data) {
        if (current->next == head) {
            free(current);
            head = NULL;
            printf("Node with value %d deleted successfully.\n", data);
            return;
        }
        while (current->next != head) {
            current = current->next;
        }
        struct Node* temp = head;
        head = head->next;
        current->next = head;
        free(temp);
        printf("Node with value %d deleted successfully.\n", data);
        return;
    }
    prev = head;
    current = head->next;
    while (current != head && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == head) {
        printf("Node with value %d not found.\n", data);
        return;
    }
    prev->next = current->next;
    free(current);
    printf("Node with value %d deleted successfully.\n", data);
}
void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Circular Singly Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Node by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value of the node to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 4:
                displayList();
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}