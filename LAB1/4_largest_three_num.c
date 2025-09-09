//Q4 Write a C program to find the largest of three numbers.

#include<stdio.h>
int main(){
    int num1, num2, num3;
    printf("Enter The  First Number: ");
    scanf("%d",&num1);
    printf("Enter The  Second Number: ");
    scanf("%d",&num2);
    printf("Enter The  Third Number: ");
    scanf("%d",&num3);

    if(num1 > num2 && num1 > num3){
        printf("The Largest Number Is: %d", num1);
    }
    else if(num2 > num1 && num2 > num3){
        printf("The Largest Number Is: %d", num2);
    }
    else{
        printf("The Largest Number Is: %d", num3);
    }
    return 0;
}