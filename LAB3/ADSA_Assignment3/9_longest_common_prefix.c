// Q9) Write a function to find the longest common prefix string amongst an array of strings. 
// If there is no common prefix, return an empty string "". 
#include <stdio.h>
#include <string.h>
#define MAX 100
#define STRINGS 10
char* longestCommonPrefix(char arr[STRINGS][MAX], int n) {
    if (n == 0) return "";
    char* prefix = arr[0];

    for (int i = 1; i < n; i++) {
        int j = 0;
        while (prefix[j] && arr[i][j] && prefix[j] == arr[i][j]) {
            j++;
        }
        prefix[j] = '\0';
        if (prefix[0] == '\0') return "";
    }
    return prefix;
}
int main() {
    char arr[STRINGS][MAX];
    int n;
    printf("Enter number of strings (max %d): ", STRINGS);
    scanf("%d", &n);
    getchar();
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        fgets(arr[i], MAX, stdin);
        arr[i][strcspn(arr[i], "\n")] = 0;
    }
    char* result = longestCommonPrefix(arr, n);
    if (strlen(result) == 0) {
        printf("No common prefix found.\n");
    } 
    else {
        printf("Longest common prefix: %s\n", result);
    }
    return 0;
}