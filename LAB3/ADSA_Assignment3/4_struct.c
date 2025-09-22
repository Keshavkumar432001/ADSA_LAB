// Q4) Define a structure Student with fields name, rollNumber, and marks. Write a program to 
// input details of n students and then display the details of the student with the highest marks.
#include<stdio.h>
#include<string.h>

struct student {
    char name[50];
    int rollNum;
    float marks;
};
void highmark(struct student students[], int n) {
    int i, max = 0;
    for (i = 1; i < n; i++) {
        if (students[i].marks > students[max].marks) {
            max = i;
        }
    }
    printf("High Marks Student:\n");
    printf("Name: %s\n", students[max].name);
    printf("Roll Number: %d\n", students[max].rollNum);
    printf("Marks: %.2f\n", students[max].marks);
}
int main() {
    int n, i;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct student students[n];
    for (i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNum);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
    highmark(students, n);
    return 0;
}