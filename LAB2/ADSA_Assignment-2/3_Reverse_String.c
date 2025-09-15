// Write a C program to reverse a string.
#include <stdio.h>
#include <string.h>
int main(){
    char char1[] = "User Name";
    int n = strlen(char1);
    char char2[n+1];
    // Reverse By Creating A New Array.
    for(int i = 0; i < n; i++){
        char2[i] = char1[n-i-1];
    }   
    char2[n] = '\0';
    printf("The Reversed String Is: %s\n", char2);

    return 0;
}