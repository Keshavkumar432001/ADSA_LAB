//Q2 A cashier mistakenly enter two values in reverse so Write a C program to swap the two numbers.

#include <stdio.h>

int main(){

    int num1, num2, temp;
    printf("Enter The First Number: ");
    scanf("%d", &num1);
    printf("Enter The Second Number: ");
    scanf("%d", &num2);
    temp = num1;
    num1 = num2;
    num2 = temp;
    printf("after Swapping: \nThe First Number IS:%d \nThe Second Number Is:%d", num1, num2);
    return 0;

}