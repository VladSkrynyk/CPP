#include <iostream>
#include <cstdlib>

using namespace std;

void product_matrixs(int** matr1, int** matr2, int** res,
	int n, int m, int k) {
	int index = 0, prod = 0;
	int d = n * k;
	int* row = (int*)malloc(d * sizeof(int));
	int ind = 0;
	for (int i = 0; i < n; i++) {
		index = 0;
		for (int j = 0; j < k; j++) {
			prod = 0;
			for (int l = 0; l < m; l++) {
				prod += matr1[i][l] * matr2[l][index];
			}
			row[ind] = prod;
			ind++;
			index++;
		}
	}

	int cur_index = 0;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < k; c++) {
			res[r][c] = row[cur_index];
			cur_index++;
		}
	}
}

int** fill_matrix( int r, int c) {

	int** matrix = (int**)malloc(r * sizeof(int*));
	for (int i = 0; i < r; i++)
		matrix[i] = (int*)malloc(c * sizeof(int));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("Input a[%d][%d]: ", i, j);
			scanf_s("%d", &matrix[i][j]);
		}
	}

	return matrix;
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

void free_matrix(int** matrix) {
	free(matrix);
}

int main() {
	int n, prev_r, prev_c;
	cout << "Input number of matrixs: ";
	cin >> n;

	int*** array_matrix = (int***)malloc(n * sizeof(int**));

	int r, c;
	cout << "Input dimension of 1 matrix: ";
	cin >> r >> c;

	array_matrix[0] = fill_matrix(r, c);

	int** prev_matrix = array_matrix[0];

	prev_r = r;
	prev_c = c;

	int** res = array_matrix[0];
	
	for (int i = 1; i < n; i++) {
		int r, c;
		cout << "Input dimension of " << i + 1 << " matrix: ";
		cin >> r >> c;

		if (prev_c == r) {
			array_matrix[i] = fill_matrix(r, c);
			product_matrixs(res, array_matrix[i], res, prev_r, prev_c, r);
			prev_matrix = array_matrix[i];
		}

		
		show_matrix(array_matrix[i], r, c);
		prev_r = r;
		prev_c = c;
	}
	show_matrix(res, r, prev_c);

	return 0;
}