// Q7) Define a structure Date with fields day, month, and year. Write a program to input two dates 
// and determine which date is earlier.
#include<stdio.h>
struct date {
    int day;
    int month;
    int year;
};
 int main() {
    struct date date1, date2;
    printf("Enter first date (day month year): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);
    printf("Enter second date (day month year): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);

    if (date1.year < date2.year || 
       (date1.year == date2.year && date1.month < date2.month) || 
       (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day)) {
        printf("The earlier date is: %02d/%02d/%04d\n", date1.day, date1.month, date1.year);
    } 
    else if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day) {
        printf("Both dates are the same: %02d/%02d/%04d\n", date1.day, date1.month, date1.year);
    } 
    else {
        printf("The earlier date is: %02d/%02d/%04d\n", date2.day, date2.month, date2.year);
    }

    return 0;
}