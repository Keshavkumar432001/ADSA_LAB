//Q14 Write a C program to count vowels in a string.
#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    int i, count = 0;
    printf("Enter A String: ");
    fgets(str, sizeof(str), stdin);
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            count++;
        }
    }
    printf("Number Of Vowels In The String Is: %d", count);
    return 0;
}