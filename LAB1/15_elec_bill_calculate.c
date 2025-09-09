/* Q15 Write a C program to perform electricity bill calculation
// A company charges electricity bill as:
// For first 100 units: ₹5/unit
// Next 100 units: ₹7/unit
// Above 200 units: ₹10/unit */

#include <stdio.h>
int main() {
    int unit;
    int total_bill = 0;

    printf("Enter the number of units consumed: ");
    scanf("%d", &unit);

    if (unit <= 100) {
        total_bill = unit * 5;
    }
    else if (unit <= 200) {
        total_bill = (100 * 5) + (unit - 100) * 7;
    }
    else {
        total_bill = (100 * 5) + (100 * 7) + (unit - 200) * 10;
    }

    printf("Total Electricity Bill Is: %d", total_bill);
return 0;
}