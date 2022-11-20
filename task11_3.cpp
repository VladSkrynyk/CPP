#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

void task_a() {
	FILE* fileW;
	fopen_s(&fileW, "task11_3a_F.txt", "wb");

	FILE* file1W;
	fopen_s(&file1W, "task11_3a_G.txt", "wb");

	int userInput;
	printf("Input number => ");
	scanf_s("%d", &userInput);

	while (userInput != 0) {
		fprintf(fileW, "%d\n", userInput);

		if (userInput % 2 == 0) {
			fprintf(file1W, "%d\n", userInput);
		}

		printf("Input number => ");
		scanf_s("%d", &userInput);
	}

	fclose(fileW);
	fclose(file1W);
}

void task_b() {
	FILE* fileW;
	fopen_s(&fileW, "task11_3b_F.txt", "wb");

	FILE* file1W;
	fopen_s(&file1W, "task11_3b_G.txt", "wb");

	int userInput;
	printf("Input number => ");
	scanf_s("%d", &userInput);

	while (userInput != 0) {
		fprintf(fileW, "%d\n", userInput);
		int a = 3;
		double p = log10(userInput) / log10(a);
		if (p - (int)p == 0) {
			fprintf(file1W, "%d\n", userInput);
		}

		printf("Input number => ");
		scanf_s("%d", &userInput);
	}

	fclose(fileW);
	fclose(file1W);
}

void task_v() {
	FILE* fileW;
	fopen_s(&fileW, "task11_3v_F.txt", "wb");

	FILE* file1W;
	fopen_s(&file1W, "task11_3v_G.txt", "wb");

	int userInput;
	printf("Input number => ");
	scanf_s("%d", &userInput);

	while (userInput != 0) {
		fprintf(fileW, "%d\n", userInput);
		double p = sqrt(userInput) - (int)sqrt(userInput);
		if (p == 0) {
			fprintf(file1W, "%d\n", userInput);
		}

		printf("Input number => ");
		scanf_s("%d", &userInput);
	}

	fclose(fileW);
	fclose(file1W);
}

void task_g() {
	FILE* fileW;
	fopen_s(&fileW, "task11_3g_F.txt", "wb");

	FILE* file1W;
	fopen_s(&file1W, "task11_3g_G.txt", "wb");

	int userInput;
	printf("Input number => ");
	scanf_s("%d", &userInput);

	while (userInput != 0) {
		fprintf(fileW, "%d\n", userInput);
		int count = 0;
		for (int i = 2; i < (userInput - 1); i++) {
			if (userInput % i == 0) count++;
		}
		
		if (count == 1) {
			fprintf(file1W, "%d\n", userInput);
		}

		printf("Input number => ");
		scanf_s("%d", &userInput);
	}

	fclose(fileW);
	fclose(file1W);
}

void task_d() {
	FILE* fileW;
	fopen_s(&fileW, "task11_3d_F.txt", "wb");

	FILE* file1W;
	fopen_s(&file1W, "task11_3d_G.txt", "wb");

	int userInput;
	printf("Input number => ");
	scanf_s("%d", &userInput);

	while (userInput != 0) {
		fprintf(fileW, "%d\n", userInput); 
		
		char str[5];
		sprintf_s(str, "%d", userInput);
		_strrev(str);
		char* ptr;
		int userInputReverced = strtol(str, &ptr, 10);
		if (userInput == userInputReverced) fprintf(file1W, "%d\n", userInput);

		printf("Input number => ");
		scanf_s("%d", &userInput);
	}

	fclose(fileW);
	fclose(file1W);
}

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

int main8() {
	//task_a();
	//task_b();
	//task_v();
	//task_g();
	//task_d();
	//task_e();

	return 0;
}