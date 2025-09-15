// Write a C program to count the number of vowels in a string.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int vowelcount(char str1[]) {
    int count = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        char c = tolower(str1[i]);
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
            count++;}
    }
    return count;
}
int voweltable(char str1[]) {
    char tab[256] = {0};
    tab['a']=tab['e']=tab['i']=tab['o']=tab['u']=1;
    tab['A']=tab['E']=tab['I']=tab['O']=tab['U']=1;

    int count = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        if (tab[(unsigned char)str1[i]]) {
            count++;}
    }
    return count;
}
int main() {
    char text[200];
    printf("Enter a comment: ");
    fgets(text, sizeof(text), stdin);
    int n = strlen(text);
    if (n > 0 && text[n-1] == '\n') {
        text[n-1] = '\0';}

    printf("Vowel count by using traverse method: %d\n", vowelcount(text));
    printf("Vowel count by using lookup table: %d\n", voweltable(text));

    return 0;
}
