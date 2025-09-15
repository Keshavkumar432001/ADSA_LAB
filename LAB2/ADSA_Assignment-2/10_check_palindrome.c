// Write a C program to check the number is palindrome or not.
#include <stdio.h>
#include <string.h>

// Method a: Convert to string.
int palind_check(int num) {
    char str[50];
    sprintf(str, "%d", num);
    int i = 0, j = strlen(str) - 1;

    while (i < j) {
        if (str[i] != str[j]) {
            return 0; }
        i++;
        j--;
    }
    return 1;
}
// Method b: Reverse digits mathematically.
int palindrome_math(int num) {
    int original = num;
    int rev = 0;

    while (num > 0) {
        int digit = num % 10;
        rev = rev * 10 + digit;
        num = num / 10;
    }

    return (rev == original);
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (palind_check(number)){
        printf("Number %d is a palindrome\n", number);}
    else{
        printf("Number %d is not a palindrome\n", number);}

    if (palindrome_math(number)){
        printf("%d is a palindrome\n", number);}
    else{
        printf("%d is not a palindrome\n", number);
        }
    return 0;
}