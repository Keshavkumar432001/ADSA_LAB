//Q13 Write a C program to find maximum element in an array.
#include<stdio.h>
int main(){
    int n, i,max;
    printf("Enter The Number Of Elements In The Array: ");
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i < n; i++){
        printf("Enter The Element Of The Array: ");
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    for(i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    printf("The Maximum Element In The Array Is: %d", max);
    return 0;
}