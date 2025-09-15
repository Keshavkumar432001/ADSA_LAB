// Write a C program to find the factorial of a number.
#include <stdio.h>


// Recursive Way To Find The Factorial.
int rec_fact(int n){
        if(n <0){
            printf("Factorial Is Not Defined For Negative Numbers.\n");
            return -1;
        }
        if(n <= 1){
            return 1;
        } 
        else 
        {
            return n * rec_fact(n - 1);
        }
    }

int main(){
    int n, fact = 1;
    printf("Enter A Number To Find Factorial: ");
    scanf("%d", &n);

    // Iterative Way To Find The Factorial.
    if(n>=0)
    {

        for(int i = 1; i <= n; i++){
        fact *= i;
        }
        printf("The Factorial Of %d Using Iterative Is: %d\n", n, fact);
    }
    else{
        printf("Factorial Is Not Defined For Negative Numbers.\n");
        return -1;
    }

    int rec = rec_fact(n);
    printf("The Factorial Of %d Using Recursion Is: %d\n", n, rec);
    return 0;
}