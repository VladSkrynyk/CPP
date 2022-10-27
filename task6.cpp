#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int inputVector(double* arr, int n) {

	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		int res = scanf_s("%lf", &arr[i]);

		if (res != 1) return i;
	}
	return n;
}

void showVect(const double* v, int n) {
	printf("(");
	for (int i = 0; i < n; i++) {
		printf("%lf, ", v[i]);
	}
	printf(")\n");
}

void deleteVect(double* v) {
	free(v);
}

double* sum_vectors(double* v1, double* v2, int n) {
	double* v3 = (double*)malloc(n * sizeof(*v1));

	for (int i = 0; i < n; i++) {
		v3[i] = v1[i] + v2[i];
	}

	return v3;
}

double product(double* v1, double* v2, int n) {
	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += v1[i] * v2[i];
	}

	return sum;
}

int main() {
	int n1, n2;
	printf("Input n1:");
	scanf_s("%d", &n1);

	printf("Input n2:");
	scanf_s("%d", &n2);

	if (n1 >= 20 || n1 >= 20 || n1 != n2) {
		printf("n must be < 20!");
		return -1;
	}

	double* v1 = (double*)malloc(n1 * sizeof(*v1));
	double* v2 = (double*)malloc(n2 * sizeof(*v2));

	inputVector(v1, n1);
	showVect(v1, n1);

	inputVector(v2, n2);
	showVect(v2, n2);

	double* v3 = sum_vectors(v1, v2, n1);
	double v4 = product(v1, v2, n1);

	showVect(v3, n1);
	printf("res => %lf", v4);

}