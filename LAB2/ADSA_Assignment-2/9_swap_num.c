// Write a C program to swap two numbers without using a temporary variable.
#include <stdio.h>

int main() {
    int a, b;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("Using Arithmetic\n");
    printf("Before swap: a = %d, b = %d\n", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("After swap:  a = %d, b = %d\n", a, b);
    printf("Using XOR\n");
        printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("Before swap: a = %d, b = %d\n", a, b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("After swap:  a = %d, b = %d\n", a, b);

    return 0;
}