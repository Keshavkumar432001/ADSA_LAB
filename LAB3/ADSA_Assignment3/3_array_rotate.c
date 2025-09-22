// Q3) Write a function to rotate an array of n elements to the right by k positions. For example, 
// for array [1, 2, 3, 4, 5] and k = 2, the rotated array should be [4, 5, 1, 2, 3]. Try to do in O(n) 
// time complexity 
#include <stdio.h>
int rotate(int arr2[], int n, int k){
    int rotated[n];
    for (int i = 0; i < n; i++) {
        rotated[(i + k) % n] = arr2[i];
    }
    printf("Rotated array: ");
    for (int i = 0; i < n; i++) {
    printf("%d ", rotated[i]);
    }
}

int main(){
    int n , k;
    int arr1[] = {1, 2, 3, 4, 5};
    n = sizeof(arr1) / sizeof(arr1[0]);
    printf("Enter the number of position to rotate the array:");
    scanf("%d", &k);
    k = k % n;
    rotate(arr1, n, k);
    //rotate[] = {4,5,1,2,3}

    return 0;
}
