#include <stdio.h>
#include <stdlib.h>

void getCofactor(int** mat, int** temp, int p, int q, int n) {
    int i = 0, j = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];

                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinantOfMatrix(int** mat, int n) {
    int D = 0; 

    if (n == 1)
        return mat[0][0];

    int** temp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        temp[i] = (int*)malloc(n * sizeof(int));

    int sign = 1; 
    for (int f = 0; f < n; f++) {
        getCofactor(mat, temp, 0, f, n);
        
        D += sign * mat[0][f]
            * determinantOfMatrix(temp, n - 1);
        sign = -sign;
    }

    return D;
}

void fill_matrix(int** matrix, int r, int c) {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("Input a[%d][%d]: ", i, j);
			scanf_s("%d", &matrix[i][j]);
		}
	}
}

void show_matrix(int** matrix, int r, int c) {

	for (int i = 0; i < r; i++) {
		printf("( ");
		for (int j = 0; j < c; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf(" )\n");
	}

}

int main() {
	int r;

	printf("Input r(rows) and c(columns): ");
	scanf_s("%d", &r);
    
    int** matr = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++)
        matr[i] = (int*)malloc(r * sizeof(int));

    fill_matrix(matr, r, r);

    printf( "Determinant of the matrix is : %d", determinantOfMatrix(matr, r));
    
	return 0;
}