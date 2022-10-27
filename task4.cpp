#include <stdio.h>

void input_array(int* array) {
	for (int i = 0; i < 5; i++) {
		printf("Input a[%d]: ", i);
		scanf_s("%d", &array[i]);
	}
}

int find_max(int* array) {
	int max_ele = array[0];

	for (int i = 0; i < 5; i++) {
		if (array[i] > max_ele) {
			max_ele = array[i];
		}
	}

	return max_ele;
}

int main() {

	int array[5];
	input_array(array);
	
	printf("Res => %d", find_max(array));

	return 0;
}