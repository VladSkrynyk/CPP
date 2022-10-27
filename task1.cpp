#include <stdio.h>

int main() {
	int array[5] = { 1,2,3,4,5 };

	float number;
	printf("Input number: ");
	scanf_s("%f", &number);

	int count = 0;

	for (int i = 0; i < 5; i++) {
		if (array[i] < number) {
			count++;
		}
	}

	printf("Res => %d", count);

	return 0;
}