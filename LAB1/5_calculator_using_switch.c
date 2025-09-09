//Q5 Write a C program to make a simple calculator using switch case.

#include<stdio.h>
int main(){
    float num1, num2;
    char operator;
    printf("Wellcome To Simple Calculator");
    printf("Enter The Operation Which You Want To Perform:+ - * / :");
    scanf("%c", &operator);
    printf("Enter The First Number:");
    scanf("%f", &num1);
    printf("Enter The Second Number:");
    scanf("%f", &num2);

    switch(operator){
        case '+':
            printf("The Sum Of Two Number Is: %f", num1 + num2);
            break;
        case '-':
            printf("The Subtraction Of Two Number Is: %f", num1 - num2);
            break;
        case '*':
            printf("The Multiplication Of Two Number Is: %f", num1 * num2);
            break;
        case '/':
            printf("The Division Of Two Number Is: %f", num1 / num2);
            break;              
        default:
        printf("Invalid Operator");
        break;
    }

    return 0;
}