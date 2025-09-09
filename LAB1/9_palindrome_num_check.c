//Q9 Write a C program to check PIN entered in ATM forward=reverse.
#include<stdio.h>
int main(){
    int num, original_num, reverse_num = 0, remainder;
    printf("Enter An Integer: ");
    scanf("%d", &num);
    original_num = num;
    while(num != 0){
        remainder = num % 10;
        reverse_num = reverse_num * 10 + remainder;
        num /= 10;
    }
    if(original_num == reverse_num){
        printf("Your ATM PIN contains palindrome number.");
    }
    else{
        printf("Your ATM PIN is not palindrome.");
    }
    return 0;
}