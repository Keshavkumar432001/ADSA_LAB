//Q16 Write a recursive function to calculate the factorial of a given number.
#include<stdio.h>

int factorial(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * factorial(n - 1);
    }
}
int main(){
    int num;
    printf("Enter A Positive Integer: ");
    scanf("%d", &num);
    if(num < 0){
        printf("Factorial Is Not Defined For Negative Numbers.");
    }
    else{
        printf("Factorial Of %d Is: %d", num, factorial(num));
    }
    return 0;
}