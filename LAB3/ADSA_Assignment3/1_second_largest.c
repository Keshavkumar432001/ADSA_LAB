// Q1)Write a program to find the second largest element in an integer array without sorting the array. Consider the array may contain duplicate values.
#include <stdio.h>

int seclarge(int arr2[], int n) {
    int first, second;
    first = second = -1;

    for (int i = 0; i < n; i++) {
        if (arr2[i] > first) {
            second = first;
            first = arr2[i];
        } 
        else if (arr2[i] > second && arr2[i] != first) {
            second = arr2[i];}
    }
    return second;
}
int main() {
    int arr1[] = {12, 35, 1, 10,10, 34,38, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int sec = seclarge(arr1, n);
    if (sec!= -1) {
        printf("The second largest element is %d\n", sec);
    } 
    else {
        printf("There is no second largest element.\n");}
    return 0;
}