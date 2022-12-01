#include <stdio.h>
#include <stdlib.h>
#include "COMMANDPROMPT.h"

/*
* Функція яка по черзі викликає відповідні функції і виводить на консоль результат їх роботи або створює відповідні файли з 
* данними( в залежності який опцію перевірки вибере користувач).
*/
int main(int argc, char* argv[]) {
	char option1[20] = "";
	if (argc == 2) {
		//1
		printf("Test 1:\n");
		if (task1(argv[1]) == 0) {
			printf("Test 1 successfully passed\n");
		}
		else printf("Test 1 failed\n");

		//2
		printf("Test 2:\n");
		if (task2(argv[1]) == 0) {
			printf("Test 2 successfully passed\n");
		}
		else printf("Test 2 failed\n");

		//3
		printf("Test 3:\n");
		if (task3(argv[1]) == 0) {
			printf("Test 3 successfully passed\n");
		}
		else printf("Test 3 failed\n");

		//4
		printf("Test 4:\n");
		if (task4(argv[1]) == 0) {
			printf("Test 4 successfully passed\n");
		}
		else printf("Test 4 failed\n");

		//5
		printf("Test 5:\n");
		if (task5(argv[1]) == 0) {
			printf("Test 5 successfully passed\n");
		}
		else printf("Test 5 failed\n");

		//6
		printf("Test 6:\n");
		if (task6(argv[1]) == 0) {
			printf("Test 6 successfully passed\n");
		}
		else printf("Test 6 failed\n");

		//7
		printf("Test 7:\n");
		if (task7(argv[1]) == 0) {
			printf("Test 7 successfully passed\n");
		}
		else printf("Test 7 failed\n");


		return 0;
	}
	else {
		printf("Choose your option 1 or 2\n1 -> console input\n2 -> data from file\n=>");
		fgets(option1, 50, stdin);

		option1[strlen(option1) - 1] = '\0';
	}
	
	
	//1
	printf("test 1:\n");
	if (task1(option1) == 0) {
		printf("test 1 successfully passed\n");
	}
	else printf("test 1 failed\n");

	//2
	printf("Test 2:\n");
	if (task2(option1) == 0) {
		printf("Test 2 successfully passed\n");
	}
	else printf("Test 2 failed\n");

	//3
	printf("Test 3:\n");
	if (task3(option1) == 0) {
		printf("Test 3 successfully passed\n");
	}
	else printf("Test 3 failed\n");

	//4
	printf("Test 4:\n");
	if (task4(option1) == 0) {
		printf("Test 4 successfully passed\n");
	}
	else printf("Test 4 failed\n");

	//5
	printf("Test 5:\n");
	if (task5(option1) == 0) {
		printf("Test 5 successfully passed\n");
	}
	else printf("Test 5 failed\n");

	//6
	printf("Test 6:\n");
	if (task6(option1) == 0) {
		printf("Test 6 successfully passed\n");
	}
	else printf("Test 6 failed\n");

	//7
	printf("Test 7:\n");
	if (task7(option1) == 0) {
		printf("Test 7 successfully passed\n");
	}
	else printf("Test 7 failed\n");


	return 0;
}