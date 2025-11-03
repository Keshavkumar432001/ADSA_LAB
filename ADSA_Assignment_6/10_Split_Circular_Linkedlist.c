// Q10.Write a program to split a circular linked list into two halves and display both lists.
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
void splitList(struct Node* head, struct Node** head1_ref, struct Node** head2_ref) {
    struct Node *slow_ptr = head, *fast_ptr = head;

    if (head == NULL)
        return;

    while (fast_ptr->next != head && fast_ptr->next->next != head) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    if (fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;

    *head1_ref = head;

    if (head->next != head)
        *head2_ref = slow_ptr->next;

    fast_ptr->next = slow_ptr->next;
    slow_ptr->next = head;
}
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Circular Linked List: ");
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
        printf("1. Insert at End\n");
        printf("2. Split List\n");
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
                        newNode->next = head;
                    } else {
                        struct Node* temp = head;
                        while (temp->next != head) {
                            temp = temp->next;
                        }
                        temp->next = newNode;
                        newNode->next = head;
                    }
                }
                break;
            case 2: {
                struct Node *head1 = NULL, *head2 = NULL;
                splitList(head, &head1, &head2);
                printf("First half:\n");
                displayList(head1);
                printf("Second half:\n");
                displayList(head2);
                break;
            }

            case 3:
                displayList(head);
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