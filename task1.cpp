#include <iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter the number of items:";
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cout << "Input a[" << i << "]: ";
		cin >> arr[i];
	}

	cout << "Array => [ ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << " ]" << endl;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i] * arr[i];
	}
	cout << "Res => " << sum << endl;

	delete[] arr;

	return 0;
}