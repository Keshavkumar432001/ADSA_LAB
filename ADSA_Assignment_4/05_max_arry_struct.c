// Q5. Write a C program to find the highest marks among n students using a structure array.
#include <stdio.h>
struct student {
    char name[50];
    int marks;
};
int main(){
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    struct student std[n];
    for(int i=0; i<n; i++){
        printf("Enter name and marks of student %d: ", i+1);
        scanf("%s %d", std[i].name, &std[i].marks);
    }
    struct student *topper = &std[0];
    for(int i=1; i<n; i++){
        if(std[i].marks > topper->marks){
            topper = &std[i];
        }
    }
    printf("Topper: %s with marks %d\n", topper->name, topper->marks);
    return 0;
}