#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void product_matrixs(int** matr1, int** matr2, int** res,
	int n, int m, int k) {
	int index = 0, prod = 0;
	vector<int> row;
	for (int i = 0; i < n; i++) {
		index = 0;
		for (int j = 0; j < k; j++) {
			prod = 0;
			for (int l = 0; l < m; l++) {
				prod += matr1[i][l] * matr2[l][index];
			}
			row.push_back(prod);
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

int main() {
	int n, m, k;

	cout << "Input n m k:";
	cin >> n >> m >> k;
	
	int** matr1 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		matr1[i] = (int*)malloc(m * sizeof(int));

	int** matr2 = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
		matr2[i] = (int*)malloc(k * sizeof(int));

	int** result = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		result[i] = (int*)malloc(k * sizeof(int));

	cout << "Input 1 martix =>" << endl;
	fill_matrix(matr1, n, m);

	cout << "Input 2 martix =>" << endl;
	fill_matrix(matr2, m, k);

	show_matrix(matr1, n, m);
	show_matrix(matr2, m, k);

	product_matrixs(matr1, matr2, result, n, m, k);

	show_matrix(result, n, k);

	return 0;
}