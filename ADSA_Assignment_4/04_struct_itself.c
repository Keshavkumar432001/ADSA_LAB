// Q4. Can a struct contain a pointer to itself? Give an example.
// Answer: Yes, a struct can contain a pointer to itself.
#include<stdio.h>
struct node {
    int data;
    struct node * next;
};
int main(){
    struct node node1, node2;
    node1.data = 10;
    node2.data = 20;
    node1.next = &node2;
    node2.next = NULL;
    printf("Node 1 data: %d\n", node1.data);
    printf("Node 2 data: %d\n", node1.next->data);
    return 0;
}