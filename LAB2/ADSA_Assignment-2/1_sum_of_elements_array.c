// Q1 Write a C program to find the sum of all elements in an array.
#include <stdio.h>

    int recursive_sum(int arr[], int n) 
    {
        if (n <= 0) 
        {
            return 0;
        } 
        else {
            return arr[n - 1] + recursive_sum(arr, n - 1);
        }
    }
    
int main() {
    int n, sum = 0,rec_sum = 0;

    // We Have Given Daily Sales Of A Shop In An Array.
    int arr[] = {100, 200, 150, 300, 280};
    n = sizeof(arr) / sizeof(arr[0]);

    // Iterative Way To Compute The Sum.
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("The Sum Of Elements In The Array Is: %d\n", sum);

    // Recursive Way To Compute The Sum.
    rec_sum = recursive_sum(arr, n);
    printf("The Sum Of Elements In The Array Using Recursion Is: %d ", rec_sum);


 return 0;
}