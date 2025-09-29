// Q1. Write a program to swap two complex numbers using a struct.
#include <stdio.h>
struct Complex {
    float real;
    float imag;
};
void swap(struct Complex *c1, struct Complex *c2) {
    struct Complex temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}
int main() 
{
    struct Complex c1, c2;
    printf("Enter real and imaginary parts of first complex number: ");
    scanf("%f %f", &c1.real, &c1.imag);
    printf("Enter real and imaginary parts of second complex number: ");
    scanf("%f %f", &c2.real, &c2.imag);
    printf("Before swapping:\n");
    printf("First complex number: %.2f + %.2fi\n", c1.real, c1.imag);
    printf("Second complex number: %.2f + %.2fi\n", c2.real, c2.imag);
    swap(&c1, &c2);
    printf("After swapping:\n");
    printf("First complex number: %.2f + %.2fi\n", c1.real, c1.imag);
    printf("Second complex number: %.2f + %.2fi\n", c2.real, c2.imag);
    return 0;
}