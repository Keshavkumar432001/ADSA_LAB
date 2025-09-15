// Write a C program to search an element using linear search.
#include <stdio.h>
int main(){
    int n,temp=0,search_id;
    // Search For A Customer ID In A Small Dataset.
    int arr[] = {101, 202, 303, 404, 505};
    n = sizeof(arr) / sizeof(arr[0]);
    printf("Enter Customer ID To Search: ");
    scanf("%d", &search_id);
    for(int i = 0; i < n; i++){
        if(arr[i] == search_id){
            temp = 1;
            printf("Customer ID %d Found At Index %d\n", search_id, i);
            break;
        }
    }
    if(temp == 0){
        printf("Customer ID %d Not Found\n", search_id);
    }

    return 0;
}