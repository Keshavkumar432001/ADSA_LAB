// Q2. Design a function that performs partial selection sort — it only sorts the first k smallest elements.
#include <stdio.h>
void partialSelectionSort(int arr[], int n, int k) {
    for (int i = 0; i < k; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        printf("Iteration %d: ", i + 1);
        for (int m = 0; m < n; m++) {
            printf("%d ", arr[m]);
        }
        printf("\n");
    }
}
int main() {
    int arr[] = {25, 12, 22, 64, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    partialSelectionSort(arr, n, k);
    printf("\nArray after partial selection sort (first %d elements sorted): ", k);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}