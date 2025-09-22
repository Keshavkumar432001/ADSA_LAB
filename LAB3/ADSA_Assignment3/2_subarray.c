// Q2) Given an array of integers, write a program to check if there exists a contiguous subarray 
// whose sum equals a given value S. If it exists, print the starting and ending indices of such 
// subarray. 
#include<stdio.h>
void subarray(int arr[], int n, int S) {
    int curr_sum, i, j;
    for (i = 0; i < n; i++) {
        curr_sum = arr[i];
        for (j = i + 1; j <= n; j++) {
            if (curr_sum == S) {
                printf("Subarray found from index %d to %d\n", i, j - 1);
                return;
            }
            if (curr_sum > S || j == n)
                break;
            curr_sum = curr_sum + arr[j];
        }
    }
    printf("No subarray found\n");
}
int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int S = 33;
    subarray(arr, n, S);
    return 0;
}

