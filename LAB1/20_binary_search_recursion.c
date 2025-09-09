//Q20 A library system searches for a book ID in a sorted array of IDs. Implement binary search using recursion.
#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (target < arr[mid])
            return binarySearch(arr, left, mid - 1, target);

        return binarySearch(arr, mid + 1, right, target);
    }
    return -1;
}

int main() {
    int bookid[] = {202, 250, 255, 277, 322, 344, 399, 444, 455, 450};
    int n = sizeof(bookid) / sizeof(bookid[0]);
    int target;

    printf("Enter the Book ID to search: ");
    scanf("%d", &target);

    int result = binarySearch(bookid, 0, n - 1, target);

    if (result != -1)
        printf("Book ID %d found at index %d.\n", target, result);
    else
        printf("Book ID %d not found in the system.\n", target);

    return 0;
}
