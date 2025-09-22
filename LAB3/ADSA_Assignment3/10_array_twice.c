// Q10) Given an integer array nums, return true if any value appears at least twice in the array, 
// and return false if every element is distinct.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool containsDuplicate(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int arr[20];
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (containsDuplicate(arr, n)) {
        printf("Array contains duplicates.\n");
    } 
    else {
        printf("All elements are distinct.\n");
    }
    return 0;
}