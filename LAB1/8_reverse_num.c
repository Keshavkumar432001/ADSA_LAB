//Q8 Write a C program to reverse a number.
#include<stdio.h>
int main(){
    int num, reverse_num = 0, remainder;
    printf("Enter An Integer: ");
    scanf("%d", &num);
    while(num != 0){
        remainder = num % 10;
        reverse_num = reverse_num * 10 + remainder;
        num /= 10;
    }
    printf("Reversed Number: %d", reverse_num);
    return 0;
}
