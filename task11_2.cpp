#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count_lines(const char* fname) {
	FILE* file;

	const int bufferLength = 255;
	char buffer[bufferLength];

	fopen_s(&file, fname, "r");

	int count = 0;
	while (fgets(buffer, bufferLength, file)) {
		count++;
	}

	fclose(file);
	return count;
}

int main3() {

	unsigned a;
	printf("Input a > 0 => ");
	scanf_s("%u", &a);

	int count = count_lines("task11_F.txt");
	double* array_for_f1 = (double*)malloc(count * sizeof(double));
	for (int i = 0; i < count; i++) array_for_f1[i] = 0;

    FILE* file;
	FILE* fileW;
	fopen_s(&fileW, "task11_G.txt", "wb");
    const int bufferLength = 255;
    char buffer[bufferLength];

    fopen_s(&file, "task11_F.txt", "r");

	int i = 0;
	if (file != NULL) {

		int count = 0;
		while (fgets(buffer, bufferLength, file)) {
			float number = atof(buffer);
			if (number > a) { 
				printf("Test => %f\n", number);
				fprintf(fileW, "%f\n", number);
				array_for_f1[i] = number;
				i++;
			}
		}
	}
    fclose(file);
	fclose(fileW);

	for (int i = 0; i < count; i++) printf("Test 1 => %f", array_for_f1[i]);

	FILE* file1W;
	fopen_s(&file1W, "task11_F.txt", "wb");

	for (int i = 0; i < count; i++) {
		if (array_for_f1[i] != 0) {
			fprintf(file1W, "%f\n", array_for_f1[i]);
		}
	}
	
	fclose(file1W);
	

	return 0;
}