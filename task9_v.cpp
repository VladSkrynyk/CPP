#include <iostream>
#include <cstdlib>

using namespace std;

void fill_matrix(int** matrix, int r, int c) {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("Input a[%d][%d]: ", i, j);
			scanf_s("%d", &matrix[i][j]);
		}
	}
}

void show_matrix(int** matrix, int r, int c) {
	cout << "Matrix" << endl;
	for (int i = 0; i < r; i++) {
		printf("( ");
		for (int j = 0; j < c; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf(")\n");
	}

}

int** add_row(int** matr, int r, int c) {
	int new_r = r + 1;
	int** result = (int**)malloc(new_r * sizeof(int*));
	for (int i = 0; i < new_r; i++)
		result[i] = (int*)malloc(c * sizeof(int));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			result[i][j] = matr[i][j];
		}
	}

	for (int i = r; i < r + 1; i++) {
		for (int j = 0; j < c; j++) {
			cout << "Input a[" << i << "][" << j << "]: ";
			cin >> result[i][j];
		}
	}

	show_matrix(result, new_r, c);

	return result;
}

int main() {

	int n, m;

	cout << "Input n m:";
	cin >> n >> m;

	if (n <= 0 || m <= 0) { 
		cout << "Incorrect input!";
		return -1;
	}

	int** matr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		matr[i] = (int*)malloc(m * sizeof(int));

	fill_matrix(matr, n, m);
	show_matrix(matr, n, m);

	add_row(matr, n, m);

	return 0;
}