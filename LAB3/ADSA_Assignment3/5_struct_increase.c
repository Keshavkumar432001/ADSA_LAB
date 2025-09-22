// Q5) Define a structure Employee with fields id, name, salary, and department. Write a program 
// to increase the salary of all employees in the "IT" department by 10%.
#include<stdio.h>
#include<string.h>

struct employee {
    int id;
    char name[50];
    float salary;
    char department[50];
};

int main() {
    int n, i;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    struct employee employees[n];
    
    for (i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        printf("Department: ");
        scanf("%s", employees[i].department);
    }

    for (i = 0; i < n; i++) {
        if (strcmp(employees[i].department, "IT") == 0) {
            employees[i].salary *= 1.10;
        }
    }

    printf("Employee details after increment:\n");
    for (i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f, Department: %s\n", employees[i].id, employees[i].name, employees[i].salary, employees[i].department);
    }

    return 0;
}