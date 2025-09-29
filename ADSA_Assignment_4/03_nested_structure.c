// Q3. Explain how nested structures work. Write a program where a struct for date is nested inside a struct for student.
// A nested structure is a structure that contains another structure as a member.
//In this example, we have a Date structure nested inside a Student structure to represent a student's date of birth.

#include <stdio.h>
struct Date {
    int day;
    int month;
    int year;
};
struct Student {
    char name[50];
    int marks;
    struct Date dob;
};
int main() {
    struct Student student;
    printf("Enter student name: ");
    scanf("%s", student.name);
    printf("Enter student marks: ");
    scanf("%d", &student.marks);
    printf("Enter date of birth (day month year): ");
    scanf("%d %d %d", &student.dob.day, &student.dob.month, &student.dob.year);

    printf("\nStudent Details:\n");
    printf("Name: %s\n", student.name);
    printf("Marks: %d\n", student.marks);
    printf("Date of Birth: %02d/%02d/%04d\n", student.dob.day, student.dob.month, student.dob.year);
    return 0;
}