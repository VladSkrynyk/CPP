#include <stdio.h>
#include <stdbool.h>

const int V1 = 3;
const int V2 = 3;

bool checkIfIn(double arr[V1][V2], int i1, int j1) {

	if (0 <= i1 && i1 <= 2 && 0 <= j1 && j1 <= 2) return true;

	return false;
}

void showArray(double arr[V1][V2]) {

	for (int i = 0; i < V1; i++) {
		printf("( ");
		for (int j = 0; j < V2; j++) {
			printf("%lf ", arr[i][j]);
		}
		printf(")\n");
	}
}

int main() {
	int i1, j1;
	double a;
	double arr[V1][V2] = { {1.0,2,3},{4,5,6},{7,8,9} };

	printf("Input i, j, a: ");
	scanf_s("%d, %d, %lf", &i1, &j1, &a);

	showArray(arr);
	
	if (checkIfIn(arr, i1, j1)) {
		arr[i1][j1] = a;
		showArray(arr);
	}
	else {
		printf("There is no element with index %d, %d", i1, j1);
	}

	return 0;
}