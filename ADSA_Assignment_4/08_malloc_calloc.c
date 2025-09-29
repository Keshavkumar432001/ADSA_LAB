// Q8  How calloc differs from malloc while allocating memory for an array of structures.
#include <stdio.h>
#include <stdlib.h>
struct student {
    char name[50];
    int marks;
};
int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Using malloc to allocate memory for n students
    struct student *students_malloc = (struct student *)malloc(n * sizeof(struct student));
    if (students_malloc == NULL) {
        printf("Memory allocation failed using malloc\n");
        return 1;
    }

    // Using calloc to allocate memory for n students
    struct student *students_calloc = (struct student *)calloc(n, sizeof(struct student));
    if (students_calloc == NULL) {
        printf("Memory allocation failed using calloc\n");
        free(students_malloc); // Free previously allocated memory
        return 1;
    }

    // Input data for students using malloc
    printf("Enter details of students using malloc:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter name and marks of student %d: ", i + 1);
        scanf("%s %d", students_malloc[i].name, &students_malloc[i].marks);
    }

    // Input data for students using calloc
    printf("Enter details of students using calloc:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter name and marks of student %d: ", i + 1);
        scanf("%s %d", students_calloc[i].name, &students_calloc[i].marks);
    }

    // Displaying the data entered using malloc
    printf("\nStudents entered using malloc:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: Name: %s, Marks: %d\n", i + 1, students_malloc[i].name, students_malloc[i].marks);
    }

    // Displaying the data entered using calloc
    printf("\nStudents entered using calloc:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: Name: %s, Marks: %d\n", i + 1, students_calloc[i].name, students_calloc[i].marks);
    }
    free(students_malloc);
    free(students_calloc);

    return 0;
}
