// Q10. Using realloc, write a program to increase the number of students in a dynamically allocated array of structures and input the new student details.
#include <stdio.h>
#include <stdlib.h>
struct student {
    char name[50];
    int marks;
};
int main() {
    int n, new_n;
    printf("Enter the initial number of students: ");
    scanf("%d", &n);

    struct student *students = (struct student *)malloc(n * sizeof(struct student));
    if (students == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter name and marks of student %d: ", i + 1);
        scanf("%s %d", students[i].name, &students[i].marks);
    }

    printf("Enter the new total number of students: ");
    scanf("%d", &new_n);

    struct student *temp = (struct student *)realloc(students, new_n * sizeof(struct student));
    if (temp == NULL) {
        printf("Memory reallocation failed\n");
        free(students);
        return 1;
    }
    students = temp;
    for (int i = n; i < new_n; i++) {
        printf("Enter name and marks of new student %d: ", i + 1);
        scanf("%s %d", students[i].name, &students[i].marks);
    }
    printf("All Students:\n");
    for (int i = 0; i < new_n; i++) {
        printf("Student %d: Name: %s, Marks: %d\n", i + 1, students[i].name, students[i].marks);
    }
    free(students);
    return 0;
}