//Q12 Write a C program to check given number is prime or not.
#include<stdio.h>
#include<math.h>
int main(){
    int num, i, flag = 0;
    printf("Enter An Integer: ");
    scanf("%d", &num);
    if(num <= 1){
        flag = 1;
    } 
    else {
        for(i = 2; i <= sqrt(num); i++){
            if(num % i == 0){
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0){
        printf("%d is a prime number.", num);
    } 
    else{
        printf("%d is not a prime number.", num);
    }
    return 0;
}