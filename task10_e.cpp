#include <stdio.h>
#include <math.h>

void input_array(int* arr, int n) {
	int i = 0;
	for (i; i < n; i++) {
		printf("input masuv[%d]:",i);
		scanf_s("%d", &arr[i]);
		
	}
}

void show_array(int* arr, int n) {
	int i = 0;
	
	printf("Show array => [ ");
	for (i; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("]\n");
}

bool IsPrime(int n) {
	int i, flag = 0;

	if (n == 0 || n == 1)
		flag = 1;

	for (i = 2; i <= n / 2; ++i) {
		if (n % i == 0) {
			flag = 1;
			break;
		}
	}


	if (flag == 0)
		return true;
	else
		return false;
}

void task10_e(int* arr, int n)
{
	int count = 0;
	int i = 0;
	for (i; i < n; i++) {
		double curent_el_d = sqrt(arr[i]);
		int curent_el_i = sqrt(arr[i]);
		printf("Double part => %lf  Int part => %d\n", curent_el_d, curent_el_i);

		if (curent_el_d - curent_el_i == 0 && IsPrime(curent_el_i)) {
			count++;
		}
	}

	printf("Main res => %d", count);
}

int main() {
	
	int arr[5] = { 12,9,25, 49, 4 };
	input_array(arr, 5);
	show_array(arr, 5);

	task10_e(arr, 5);

	return 0;
}