#include <iostream>
#include <cstdlib>

using namespace std;

void product_matrixs(int** matr1, int** matr2, int** res,
	int n1) {
	int index = 0, prod = 0;
	int d = n1 * n1;
	int* row = (int*)malloc(d * sizeof(int));
	int ind = 0;
	for (int i = 0; i < n1; i++) {
		index = 0;
		for (int j = 0; j < n1; j++) {
			prod = 0;
			for (int l = 0; l < n1; l++) {
				prod += matr1[i][l] * matr2[l][index];
			}
			row[ind] = prod;
			ind++;
			index++;
		}
	}

	int cur_index = 0;
	for (int r = 0; r < n1; r++) {
		for (int c = 0; c < n1; c++) {
			res[r][c] = row[cur_index];
			cur_index++;
		}
	}
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
	cout << "Matrix" << endl;
	for (int i = 0; i < r; i++) {
		printf("( ");
		for (int j = 0; j < c; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf(" )\n");
	}

}

void free_matrix(int** matr, int n) {
	for (int i = 0; i < n; i++) {
		free(matr[i]);
	}
	free(matr);
}

int main() {
	int n1, n2;

	cout << "Input n1 n2:";
	cin >> n1 >> n2;

	int** matr1 = (int**)malloc(n1 * sizeof(int*));
	for (int i = 0; i < n1; i++)
		matr1[i] = (int*)malloc(n1 * sizeof(int));

	int** matr2 = (int**)malloc(n2 * sizeof(int*));
	for (int i = 0; i < n2; i++)
		matr2[i] = (int*)malloc(n2 * sizeof(int));

	if (n1 != n2) {
		cout << "Different dimension!!!" << endl;
		return -1;
	}
	
	int** result = (int**)malloc(n1 * sizeof(int*));
	for (int i = 0; i < n1; i++)
		result[i] = (int*)malloc(n1 * sizeof(int));
	
	

	cout << "Input 1 martix =>" << endl;
	fill_matrix(matr1, n1, n1);

	cout << "Input 2 martix =>" << endl;
	fill_matrix(matr2, n2, n2);

	show_matrix(matr1, n1, n1);
	show_matrix(matr2, n2, n2);

	product_matrixs(matr1, matr2, result, n1);

	show_matrix(result, n1, n1);

	free_matrix(result, n1);
	free_matrix(matr1, n1);
	free_matrix(matr2, n1);

	return 0;
}