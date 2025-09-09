//Q11 Write a C program to calculate the sum of digits of a number.
#include<stdio.h>
int main(){
    int num, sum = 0, remainder;
    printf("Enter An Integer Number: ");
    scanf("%d", &num);
    while(num != 0){
        remainder = num % 10;
        sum += remainder;
        num /= 10;
    }
    printf("Sum Of Digits In A Number Is: %d", sum);
    return 0;
}