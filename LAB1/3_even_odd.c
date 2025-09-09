//Q3 Write a C program to check whether the given token number is even or odd.
#include<stdio.h>
int main()
{
    int token_num;
    printf("Enter The Token Number: ");
    scanf("%d",&token_num);
    if(token_num % 2 == 0){
        printf("The Token Number Is Even");
    }
    else{
        printf("The Token Number Is Odd");
    }
    return 0;
}