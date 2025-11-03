// Q9.Write a function to check whether a given linked list is circular or not.
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
int isCircular() {
    if (head == NULL) {
        return 1; 
    }
    struct Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}
void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != NULL && temp != head);
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Check if Circular\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                {
                    struct Node* newNode = createNode(value);
                    if (head == NULL) {
                        head = newNode;
                    } else {
                        struct Node* temp = head;
                        while (temp->next != NULL && temp->next != head) {
                            temp = temp->next;
                        }
                        temp->next = newNode;
                    }
                }
                break;

            case 2:
                if (isCircular()) {
                    printf("The linked list is circular.\n");
                } else {
                    printf("The linked list is not circular.\n");
                }
                break;

            case 3:
                displayList();
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}