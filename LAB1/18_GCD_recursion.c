//Q18 Write a C program to find GCD of two numbers using recursion.
#include<stdio.h>
int gcd(int num1, int num2){
    if(num2 == 0){
        return num1;
    }
    else{
        return gcd(num2, num1 % num2);
    }
}
int main(){
    int num1, num2, res_gcd;
    printf("Enter First Positive Integer: ");
    scanf("%d", &num1);
    printf("Enter Second Positive Integer: ");
    scanf("%d", &num2);
    if(num1 < 0 || num2 < 0){
        printf("GCD Is Not Defined For Negative Numbers.");
    }
    else{
        res_gcd = gcd(num1, num2);
        printf("GCD Of %d And %d Is: %d", num1, num2, res_gcd);
    }
    return 0;
}