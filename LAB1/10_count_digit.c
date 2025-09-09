//Q10 Write a C program to count digits in a number.
#include<stdio.h>
int main(){
    int num, count = 0;
    printf("Enter An Integer Number: ");
    scanf("%d", &num);
    while(num != 0){
        num /= 10;
        count++;
    }
    printf("Number Of Digits In A Number Is: %d", count);
    return 0;
}