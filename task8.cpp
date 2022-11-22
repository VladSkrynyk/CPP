#include <stdio.h>
#include <stdlib.h>

int main1() {

	int n;
	printf("Input n => ");
	scanf_s("%d", &n);

	FILE* filePointer;
	const int bufferLength = 255;
	char buffer[bufferLength]; 

	FILE* file1W;
	fopen_s(&file1W, "task11_8G.txt", "wb");

	fopen_s(&filePointer, "task11_8.txt", "r");

	// к-ть компонент файлу ділиться на n
	//int count = 0;
	//int max = NULL;
	//while (fgets(buffer, bufferLength, filePointer)) {
	//	count++;
	//	
	//	//printf("%s\n", buffer);
	//	char* ptr;
	//	int number = strtol(buffer, &ptr, 10);
	//	if (number > max) max = number;
	//	if (count == n) {
	//		//printf("Block, max => %d\n", max);
	//		fprintf(file1W, "%d\n", max);
	//		count = 0;
	//		max = NULL;

	//	}
	//}

	// к-ть компонент файлу не ділиться на n
	int count = 0;
	
	while (fgets(buffer, bufferLength, filePointer)) {
		count++;
	}
	fclose(filePointer);

	FILE* filePointer1;
	const int bufferLength1 = 255;
	char buffer1[bufferLength1];
	fopen_s(&filePointer1, "task11_8.txt", "r");

	int count1 = NULL;
	int max = NULL;
	while (fgets(buffer1, bufferLength1, filePointer1)) {
		count1++;
		char* ptr;
		int number = strtol(buffer1, &ptr, 10);
		if (number > max) max = number;
		if (count1 == n ) {
			//printf("block, max => %d\n", max);
			fprintf(file1W, "%d\n", max);
			count1 = 0;
			max = NULL;	
		}
	}

	fclose(filePointer1);

	FILE* filePointer2;
	const int bufferLength2 = 255;
	char buffer2[bufferLength2];
	fopen_s(&filePointer2, "task11_8.txt", "r");

	int countL = NULL;
	int max2 = NULL;
	while (fgets(buffer2, bufferLength2, filePointer2)) {
		countL++;
		char* ptr;
		int number = strtol(buffer2, &ptr, 10);
		if (number > max2 && countL > (count - n)) max2 = number;
		if (countL == count) {
			//printf("block, max => %d\n", max);
			fprintf(file1W, "%d\n", max2);
			max2 = NULL;
		}
	}
	fclose(filePointer2);
	fclose(file1W);
	

	return 0;
}