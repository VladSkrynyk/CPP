#include <stdio.h>
#include <stdlib.h>

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

int task6(double** matr, double r, double c, int k) {
	int sum = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i - j == k) sum += matr[i][j];
		}
	}

	return sum;
}

int main() {
	int k = 1;
	double r, c;

	printf("Input r(rows) and c(columns): ");
	scanf_s("%lf, %lf", &r, &c);

	double** matr = (double**)malloc(r * sizeof(double*));
	for (int i = 0; i < r; i++)
		matr[i] = (double*)malloc(c * sizeof(double));

	fill_matrix(matr, r, c);
	show_matrix(matr, r, c);

	printf("Res => %d", task6(matr, r, c, k));

	return 0;
}