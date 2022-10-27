#include <stdio.h>

int find_min(int* arr, int n) {
	int min_el = arr[0];

	for (int i = 1; i < n; i+=2) {
		if (arr[i] < min_el) {
			min_el = arr[i];
		} 
	}

	return min_el;
}

int find_max(int* arr, int n) {
	int max_el = arr[0];

	for (int i = 0; i < n; i+=2) {
		if (arr[i] > max_el) {
			max_el = arr[i];
		} 
	}

	return max_el;
}

int main() {

	int arr[7] = { 1,2,3,4,5,6,7 };
	
	printf("Res => %d", find_min(arr, 7) + find_max(arr, 7));

	return 0;
}