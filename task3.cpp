#include <stdio.h>
#define E 2.71828

double find_sum(double* array) {
	double sum = 0;

	for (int i = 0; i < 10; i++) {
		if (array[i] > E) {
			sum += array[i];
		}
	}

	return sum;
}

int main() {
	
	double array[10];
	for (int i = 0; i < 10; i++) {
		printf("Input a[%d] :", i);
		scanf_s("%lf", &array[i]);
	}

	printf("Res => %lf", find_sum(array));

	return 0;
}