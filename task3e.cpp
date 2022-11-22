#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool isPerfectSquare(int x) {
	int s = sqrt(x);
	return (s * s == x);
}

bool isFibonacci(int n) {
	return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}

void task_e() {
	FILE* fileW;
	fopen_s(&fileW, "task11_3e_F.txt", "wb");

	FILE* file1W;
	fopen_s(&file1W, "task11_3e_G.txt", "wb");

	int userInput;
	printf("Input number => ");
	scanf_s("%d", &userInput);

	while (userInput != 0) {
		fprintf(fileW, "%d\n", userInput);
		if (isFibonacci(userInput)) fprintf(file1W, "%d\n", userInput);

		printf("Input number => ");
		scanf_s("%d", &userInput);
	}

	fclose(fileW);
	fclose(file1W);
}

int main2() {
	task_e();

	return 0;
}
