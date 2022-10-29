#include <stdio.h>
#include <stdlib.h>

void fill_matrix(int** matrix, int r, int c) {

    for (int j = 0; j < r; j++) {
        printf(" Input row %i\n", j + 1);
        for (int i = 0; i < c; i++) {
            scanf_s("%d", &matrix[j][i]);
        }
    }
}

void show_matrix(int** matrix, int r, int c) {

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            printf("%d ", matrix[i][j]);
}

int main() {
    int r, c, i, j, count;

    printf("Input r(rows) and c(columns): ");
    scanf_s("%d, %d", &r, &c);

    if (r > 25 || r <= 0 || c > 25 || c <= 0) {
        printf("Wrong");
        return -1;
    }

    int** arr = (int**)malloc(r * sizeof(int*));
    for (i = 0; i < r; i++)
        arr[i] = (int*)malloc(c * sizeof(int));

    fill_matrix(arr, r, c);

    show_matrix(arr, r, c);


    for (int i = 0; i < r; i++)
        free(arr[i]);

    free(arr);

    return 0;
}