// Q9. Write a program to dynamically allocate memory for a 2D array inside a structure and store integers in it. 
#include <stdio.h>
#include <stdlib.h>
struct Matrix {
    int rows;
    int cols;
    int **data;
};
int main() {
    int r, c;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    struct Matrix matrix;
    matrix.rows = r;
    matrix.cols = c;
    matrix.data = (int **)malloc(r * sizeof(int *));
    if (matrix.data == NULL) {
        printf("Memory allocation failed for rows\n");
        return 1;
    }
    for (int i = 0; i < r; i++) {
        matrix.data[i] = (int *)malloc(c * sizeof(int));
        if (matrix.data[i] == NULL) {
            printf("Memory allocation failed for columns in row %d\n", i);
            for (int j = 0; j < i; j++) {
                free(matrix.data[j]);
            }
            free(matrix.data);
            return 1;
        }
    }
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix.data[i][j]);
        }
    }
    printf("The matrix is:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", matrix.data[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < r; i++) {
        free(matrix.data[i]);
    }
    free(matrix.data);

    return 0;
}