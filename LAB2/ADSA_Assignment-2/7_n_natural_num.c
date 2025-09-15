// Write a C program to generate first n natural numbers.
#include <stdio.h>

    void natural(int n) {
        if (n == 0) {
            return;
        }
        natural(n - 1);
        printf("%d ", n);
    } 

int main(){
    int num;
    printf("Enter A Number To Generate First N Natural Numbers: ");
    scanf("%d", &num);

    // Generating First N Natural Numbers Using Iterative Way.
    printf("The First %d Natural Numbers Are:\n", num);
    for(int i = 1; i <= num; i++){
        printf("%d ", i);
    }
    printf("\n");
    // Generating First N Natural Numbers Using Recursion.
    natural(num); 
    
    return 0;
}