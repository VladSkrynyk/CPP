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
		printf(" )\n");
	}

}

void change(int** matr, int n, int m) {
	int min_el = matr[0][0], max_el = matr[1][1], row_min = 0, row_max = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matr[i][j] < min_el) {
				min_el = matr[i][j];
				row_min = i;
			}

			if (matr[i][j] > max_el) {
				max_el = matr[i][j];
				row_max = i;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int max_element = matr[row_max][j];
			matr[row_max][j] = matr[row_min][j];
			matr[row_min][j] = max_element;
		}
	}

}

int main() {

	int n, m;

	cout << "Input n m:";
	cin >> n >> m;

	int** matr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		matr[i] = (int*)malloc(m * sizeof(int));

	cout << "Input martix =>" << endl;
	fill_matrix(matr, n, m);

	show_matrix(matr, n, m);

	change(matr, n, m);

	show_matrix(matr, n, m);

	return 0;
}