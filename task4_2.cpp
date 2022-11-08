#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int* product_matrix(int* matr1, int* matr2, int n) {
	int* result = (int*)malloc(n * sizeof(int));
	for (int p = 0; p < n; p++) {
		result[p] = 0;
	}
	
	int j = 0;
	int l = 0;
	int prev = 0;
	int size = sqrt(n);
	int help = 0;
	int index = 0;
	for (int f = 0; f < sqrt(n); f++){
		for (int i = 0; i < sqrt(n); i++) {
			//cout << "start1 ";
			for (j; j < size;) {
				//cout << "1)=> " << matr1[j] << " ";
				//cout << "2)=> " << matr2[l] << " ";
				result[index] += matr1[j] * matr2[l];
				
				j++;
				l += sqrt(n);
			}
			j -= sqrt(n);
			//cout << "\nTest :" << index << " " << result[index] << endl;
			//cout << "end1" << endl;
			
			l = prev + 1;
			prev++;
			index++;
		}
		
		l = 0;
		prev-= sqrt(n);
		j += sqrt(n);
		size += sqrt(n);
	}

	return result;
}

void fill_matrix(int* matr, int n) {
	cout << "Input array => " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Input a[" << i << "]: ";
		cin >> matr[i];
	}
}

void show_matrix(int* matr, int n) {
	cout << "Array => [ ";
	for (int i = 0; i < n; i++) {
		cout << matr[i] << " ";
	}
	cout << "]" << endl;
}

void free_matrix(int* matr, int n) {
	free(matr);
}

int main() {

	int n1, n2;

	cout << "Input n1 n2:";
	cin >> n1 >> n2;
	n1 *= n1;
	n2 *= n2;

	if (n1 != n2) {
		cout << "Different dimension!!!" << endl;
		return -1;
	}

	int* matr1 = (int*)malloc(n1 * sizeof(int));

	int* matr2 = (int*)malloc(n2 * sizeof(int));

	fill_matrix(matr1, n1);
	fill_matrix(matr2, n2);

	show_matrix(matr1, n1);
	show_matrix(matr2, n2);

	int* result = product_matrix(matr1, matr2, n1);
	show_matrix(result, n1);

	return 0;
}