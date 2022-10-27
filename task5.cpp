#include <stdio.h>

void find(int* arr) {
	int i = 0;
	int count1 = 0, count2 = 0;

	while (arr[i] != 0) {
		
		if (arr[i] % 2 == 0) {
			count1++;
		}
		else {
			count2++;
		}
		i++;
	}

	printf("Res 1: %d,  Res2: %d", count1, count2);

}

int main() {

	int arr[50] = { 12,2,3,4 };
	int i = 0;
	int user_input;
	int count = 1;
	printf("Input a[%d]: ", i);
	scanf_s("%d", &user_input);

	if (user_input == 0) {
		printf("Your array is not initialized!");
		return -1;
	}
	else {
		arr[i] = user_input;
	}

	do {
		if (count > 50) break;

		i++;
		printf("Input a[%d]: ", i);
		scanf_s("%d", &user_input);

		if (user_input != 0) {
			count++;
			arr[i] = user_input;
		}
		else {
			break;
		}
		
	} while (user_input != 0);

	find(arr);

	return 0;
}