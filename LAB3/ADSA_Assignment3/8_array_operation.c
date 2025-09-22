// Q8) Given an array of integers nums and an integer target, return indices of the two numbers 
// such that they add up to target. 
// You may assume that each input would have exactly one solution, and you may not use 
// the same element twice. 
#include <stdio.h>
void findTwoSum(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Indices of the two numbers that add up to %d are: %d and %d\n", target, i, j);
                return;
            }
        }
    }
    printf("No two numbers add up to %d\n", target);
}
int main() {
    int arr[] = {2, 7, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;
    findTwoSum(arr, n, target);
    return 0;
}
