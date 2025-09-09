//Q6 Write a C program to find the factorial of a number.

#include<stdio.h>
int main()
{
    int num, i, fact = 1;
    printf("Enter The Number:");
    scanf("%d",&num);
    if(num < 0)
    {
        printf("You Entered Negative Number Factorial Is Not Possible");
        return 0; 
    }
    else
    {
        for(i=1; i<=num; i++)
        {
            fact = fact * i;
        }
    }
    printf("The Factorial Of %d Is: %d", num, fact);
    return 0;
}