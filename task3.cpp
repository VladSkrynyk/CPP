#include <iostream>

using namespace std;

int* make_array(int n) {
	int* arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		cout << "Input a[" << i << "] => ";
		cin >> arr[i];
	}

	return arr;
}

void show_array(int* arr, int n) {
	cout << "Array => [ ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "]" << endl;

}


void free_array(int* arr) {
	free(arr);
}

int main() {
	int n1, n2;
	cout << "Input n1 n2: ";
	cin >> n1 >> n2;
	
	if (n1 != n2) {
		cout << "Dimension of vectors is different!!!" << endl;
		return -1;
	}
	else {
		int* arr1 = make_array(n1);
		show_array(arr1, n1);
		int* arr2 = make_array(n1);
		show_array(arr2, n1);

		int* res = (int*)malloc(n1 * sizeof(int));
		for (int i = 0; i < n1; i++) {
			res[i] = arr1[i] - arr2[i];
		}
		show_array(res, n1);
		free_array(res);
		free_array(arr1);
		free_array(arr2);
	}

	return 0;
}