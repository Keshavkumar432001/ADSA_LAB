// Q4. Write a function to merge two sorted linked lists into one sorted linked list. Do not use arrays or extra data structures.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    struct Node* mergedHead = NULL;
    if (l1->data < l2->data) {
        mergedHead = l1;
        l1 = l1->next;
    } else {
        mergedHead = l2;
        l2 = l2->next;
    }
    struct Node* mergedTail = mergedHead;
    while (l1 && l2) {
        if (l1->data < l2->data) {
            mergedTail->next = l1;
            l1 = l1->next;
        } else {
            mergedTail->next = l2;
            l2 = l2->next;
        }
        mergedTail = mergedTail->next;
    }
    if (l1) {
        mergedTail->next = l1;
    } else {
        mergedTail->next = l2;
    }
    return mergedHead;
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
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Creating first sorted linked list: 10 -> 30 -> 50
    push(&list1, 50);
    push(&list1, 30);
    push(&list1, 10);

    // Creating second sorted linked list: 20 -> 40 -> 60
    push(&list2, 60);
    push(&list2, 40);
    push(&list2, 20);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);
    struct Node* mergedList = mergeSortedLists(list1, list2);
    printf("Merged Sorted List: ");
    printList(mergedList);
    return 0;
}
