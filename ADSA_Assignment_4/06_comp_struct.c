// Q6. How can you compare two structures in C? Illustrate with an example comparing two student structures.
// Answer: In C, we cannot directly compare two structures Instead, we need to compare each member of the structures individually.
#include<stdio.h>
#include<string.h>
struct student {
    char name[50];
    int marks;
    int age;
};
int compstd(struct student *s1, struct student *s2) {
    if (strcmp(s1->name, s2->name) != 0) {
        return 0;
    }
    if (s1->marks != s2->marks) {
        return 0;
    }
    if (s1->age != s2->age) {
        return 0;
    }
    return 1;
}
int main(){
    struct student s1, s2;
    printf("Enter name, marks and age of student 1: ");
    scanf("%s %d %d", s1.name, &s1.marks, &s1.age);
    printf("Enter name, marks and age of student 2: ");
    scanf("%s %d %d", s2.name, &s2.marks, &s2.age);
    if(compstd(&s1, &s2)){
        printf("Students are equal.\n");
    } 
    else {
        printf("Students are not equal.\n");
    }
    return 0;
}