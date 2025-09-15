// Write a C program to check number is even or odd.
#include <stdio.h>
int main(){
    int arr[] = {11, 22, 29, 55, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    //(a).Using Modulo Operator
    printf("\nFinding Even or Odd Using Modulo Operator:\n");
    for(int i = 0; i < n; i++)
    {
        if(arr[i] % 2 == 0){
            printf("%d is Even\n", arr[i]);
        } 
        else {
            printf("%d is Odd\n", arr[i]);
        }
    }
 
    //(b).Using Bitwise Operator.
    printf("\nFinding Even or Odd Using Bitwise Operator:\n");
    for(int i = 0; i < n; i++)
    {
        if((arr[i] & 1) == 0){
            printf("%d is Even\n", arr[i]);
        } 
        else {
            printf("%d is Odd\n", arr[i]);
        }
    }
    return 0;
}