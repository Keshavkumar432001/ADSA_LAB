//Q7 Write a C program to print the fibonacci series upto n terms.
#include<stdio.h>
int main(){
    int n, first_term = 0, second_term = 1, next_term, i;
    printf("Enter The Number Of Terms: ");
    scanf("%d", &n);
    printf("Fibonacci series upto %d terms:\n",n);
    for(i = 1; i <= n; i++)
    {
        printf("%d ", first_term);
        next_term = first_term + second_term;
        first_term = second_term;
        second_term = next_term;
    }
    return 0;
}
