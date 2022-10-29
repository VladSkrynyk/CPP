#include <stdio.h>
#include <stdbool.h>

const int V1 = 3;
const int V2 = 3;

bool checkIfIn(int arr[V1][V2], int M) {
	
	for (int i = 0; i < V1; i++) {
		for (int j = 0; j < V2; j++) {
			if (arr[i][j] == M) return true;
		}
	}

	return false;
}

void showArray(int arr[V1][V2]) {

	for (int i = 0; i < V1; i++) {
		printf("( ");
		for (int j = 0; j < V2; j++) {
			printf("%d ", arr[i][j]);
		}
		printf(")\n");
	}
}

int main() {
	int N, M;
	int arr[V1][V2] = { {1,2,3},{4,5,6},{7,8,9} };

	printf("Input N, M: ");
	scanf_s("%d, %d", &N, &M);

	showArray(arr);

	if (checkIfIn(arr, M)) {
		for (int i = 0; i < V1; i++) {
			for (int j = 0; j < V2; j++) {
				if (arr[i][j] == M) arr[i][j] = N;
			}
		}

		showArray(arr);
	}
	else {
		printf("There is no element which is equal to %d", M);
	}

	return 0;
}