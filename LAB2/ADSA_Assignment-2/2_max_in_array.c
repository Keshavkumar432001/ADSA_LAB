// Q2 Write a C program to find the maximum element in an array.    
#include <stdio.h>
int main(){
    int n, max;
    // We Have Given A Temperature Reading For A Week.
    int arr[] = {36, 39, 34, 37, 42, 41, 30};
    n = sizeof(arr) / sizeof(arr[0]);
    max = arr[0];
    // Iterative Way To Find The Maximum Element.
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    printf("The Maximum Temperature Is: %d\n", max);


    return 0;
}