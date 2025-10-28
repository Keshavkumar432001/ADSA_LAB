// Q7. Write a program to merge two sorted linked lists into one sorted linked list.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    struct Node* mergedHead = NULL;
    if (l1->data < l2->data) {
        mergedHead = l1;
        l1 = l1->next;
    } else {
        mergedHead = l2;
        l2 = l2->next;
    }
    struct Node* mergedTail = mergedHead;
    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            mergedTail->next = l1;
            l1 = l1->next;
        } else {
            mergedTail->next = l2;
            l2 = l2->next;
        }
        mergedTail = mergedTail->next;
    }
    if (l1 != NULL) {
        mergedTail->next = l1;
    } else {
        mergedTail->next = l2;
    }
    return mergedHead;
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* l1 = createNode(1);
    l1->next = createNode(3);
    l1->next->next = createNode(5);
    struct Node* l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->next = createNode(6);
    printf("List 1:\n");
    printList(l1);
    printf("List 2:\n");
    printList(l2);
    struct Node* mergedList = mergeSortedLists(l1, l2);
    printf("Merged Sorted List:\n");
    printList(mergedList);
    return 0;
}