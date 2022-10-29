#include <stdio.h>
#include <stdlib.h>

void transponse(double** m1, double** m2, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			m2[j][i] = m1[i][j];
		}
	}
}

void fill_matrix(double** matrix, double r, double c) {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("Input a[%d][%d]: ", i, j);
			scanf_s("%lf", &matrix[i][j]);
		}
	}
}

void show_matrix(double** matrix, double r, double c) {

	for (int i = 0; i < r; i++) {
		printf("( ");
		for (int j = 0; j < c; j++) {
			printf("%lf ", matrix[i][j]);
		}
		printf(" )\n");
	}
		
}

int main() {
	double r, c;

	printf("Input r(rows) and c(columns): ");
	scanf_s("%lf, %lf", &r, &c);

	double** matr = (double**)malloc(r * sizeof(double*));
	for (int i = 0; i < r; i++)
		matr[i] = (double*)malloc(c * sizeof(double));
	
	double** tranp = (double**)malloc(r * sizeof(double*));
	for (int i = 0; i < r; i++)
		tranp[i] = (double*)malloc(c * sizeof(double));

	fill_matrix(matr, r, c);

	show_matrix(matr, r, c);

	transponse(matr, tranp, r, c);

	printf("Transponse\n");
	show_matrix(tranp, r, c);

	return 0;
}