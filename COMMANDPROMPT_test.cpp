#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include "COMMANDPROMPT.h"

/*
* Функція яка по черзі викликає відповідні функції і виводить на консоль результат їх роботи або створює відповідні файли з
* данними( в залежності який опцію перевірки вибере користувач).
*/
int main1(int argc, char* argv[]) {
	
	std::string option1;
	if (argc == 2) {
		option1 = argv[1];
	}
	else {
		printf("Choose your option 1 or 2\n1 -> console input\n2 -> data from file\n=>");
		std::getline(std::cin, option1);
	}

	
	
	
	//1
	std::cout << "test 1:\n";
	if (task1(option1) == 0) std::cout << "test 1 successfully passed\n";
	else std::cout << "test 1 failed\n";

	//2
	std::cout << "Test 2:\n";
	if (task2(option1) == 0) std::cout << "Test 2 successfully passed\n";
	else std::cout << "Test 2 failed\n";

	//3
	std::cout << "Test 3:\n";
	if (task3(option1) == 0) std::cout << "Test 3 successfully passed\n";
	else std::cout << "Test 3 failed\n";

	//4
	std::cout << "Test 4:\n";
	if (task4(option1) == 0) std::cout << "Test 4 successfully passed\n";
	else std::cout << "Test 4 failed\n";

	//5
	std::cout << "Test 5:\n";
	if (task5(option1) == 0) std::cout << "Test 5 successfully passed\n";
	else std::cout << "Test 5 failed\n";

	//6
	std::cout << "Test 6:\n";
	if (task6(option1) == 0) std::cout << "Test 6 successfully passed\n";
	else std::cout << "Test 6 failed\n";

	//7
	std::cout << "Test 7:\n";
	if (task7(option1) == 0) std::cout << "Test 7 successfully passed\n";
	else std::cout << "Test 7 failed\n";

	return 0;
}