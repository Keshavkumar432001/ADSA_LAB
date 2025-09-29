// Q2. Write a program to store and display information of n employees using an array of structures.
#include <stdio.h>

struct employee {
    int id;
    char name[50];
    float salary;
};
int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct employee emp[n];
    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf(" %s", emp[i].name); // To read string with spaces
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }
        printf("Employee Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Salary: %.2f\n", emp[i].salary);
    }
    return 0;
}