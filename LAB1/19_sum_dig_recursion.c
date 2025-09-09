//Q19 Write a C program to find the sum of digits of a number using recursion.
#include<stdio.h>
int sum(int n){
    if(n == 0){
        return 0;
    }
    else{
        return (n % 10) + sum(n / 10);
    }
}
int main(){
    int num, res;
    printf("Enter A Positive Integer: ");
    scanf("%d", &num);
    if(num < 0){
        printf("You Enter A Negative Numbers.");
    }
    else{
        res = sum(num);
        printf("Sum Of Digits In %d Is: %d", num, res);
    }
    return 0;
}