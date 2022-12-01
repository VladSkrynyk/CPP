#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <streambuf>
#include <iterator>
#include "COMMANDPROMPT.h"

int main() {
	bool checkF = true;

	system("cd D:/cpp/study/project1/COMMANDPROMPT_C/Debug/ && start COMMANDPROMPT_C.exe 2");
	std::cout << "Running programs in C, please wait...\n";
	Sleep(5 * 1000);

	std::cout << "Running programs in C++\n";
	//1
	std::cout << "Test 1:\n";
	task1("2");
	std::cout << "Test 1 successfully passed\n";

	//2
	std::cout << "Test 2:\n";
	task2("2");
	std::cout << "Test 2 successfully passed\n";

	//3
	std::cout << "Test 3:\n";
	task3("2");
	std::cout << "Test 3 successfully passed\n";

	//4
	std::cout << "Test 4:\n";
	task4("2");
	std::cout << "Test 4 successfully passed\n";

	//5
	std::cout << "Test 5:\n";
	if (task5("2") == 0) std::cout << "Test 5 successfully passed\n";
	else std::cout << "Test 5 failed\n";

	//6
	std::cout << "Test 6:\n";
	task6("2");
	std::cout << "Test 6 successfully passed\n";

	//7
	std::cout << "Test 7:\n";
	task7("2");
	std::cout << "Test 7 successfully passed\n";

	

	int intdate1Task1 = 0, intdate2Task1 = 0;
	float intdate1Task2 = 0, intdate2Task2 = 0;
	int intdate1Task3 = 0, intdate2Task3 = 0;
	float intdate1Task4 = 0, intdate2Task4 = 0;
	
	//1
	std::ifstream file1Task1("task1_output_v1.txt");
	std::string date1Task1;

	while (getline(file1Task1, date1Task1)) {
		//std::cout << date1Task1 << '\n';
		intdate1Task1 = atoi(date1Task1.c_str());
	}
	file1Task1.close();

	std::ifstream file2Task1("D:/cpp/study/project1/COMMANDPROMPT_C/Debug/task1_output_v1.txt");
	std::string date2Task1;

	while (getline(file2Task1, date2Task1)) {
		//std::cout << date2Task1 << '\n';
		intdate2Task1 = atoi(date2Task1.c_str());
	}
	file2Task1.close();
	
	if (intdate1Task1 != intdate2Task1) {
		std::cout << "Here1\n";
		checkF = false;
	}

	//2
	std::ifstream file1Task2("task2_output_v1.txt");
	std::string date1Task2;

	while (getline(file1Task2, date1Task2)) {
		//std::cout << date1Task2 << '\n';
		intdate1Task2 = atof(date1Task2.c_str());
	}
	file1Task2.close();

	std::ifstream file2Task2("D:/cpp/study/project1/COMMANDPROMPT_C/Debug/task2_output_v1.txt");
	std::string date2Task2;

	while (getline(file2Task2, date2Task2)) {
		//std::cout << date2Task2 << '\n';
		intdate2Task2 = atof(date2Task2.c_str());
	}
	file2Task2.close();

	if (intdate1Task2 != intdate2Task2) {
		std::cout << "Here2\n";
		checkF = false;
	}

	//3
	std::ifstream file1Task3("task3_output_v1.txt");
	std::string date1Task3;

	while (getline(file1Task3, date1Task3)) {
		//std::cout << date1Task3 << '\n';
		intdate1Task3 = atoi(date1Task3.c_str());
	}
	file1Task3.close();

	std::ifstream file2Task3("D:/cpp/study/project1/COMMANDPROMPT_C/Debug/task3_output_v1.txt");
	std::string date2Task3;

	while (getline(file2Task3, date2Task3)) {
		//std::cout << date2Task3 << '\n';
		intdate2Task3 = atoi(date2Task3.c_str());
	}
	file2Task3.close();

	if (intdate1Task3 != intdate2Task3) {
		std::cout << "Here3\n";
		checkF = false;
	}

	//4
	std::ifstream file1Task4("task4_output_v1.txt");
	std::string date1Task4;

	while (getline(file1Task4, date1Task4)) {
		//std::cout << date1Task4 << '\n';
		if (date1Task4.length() > 6) date1Task4.erase(5);
		
		intdate1Task4 = atof(date1Task4.c_str());
	}
	file1Task4.close();

	std::ifstream file2Task4("D:/cpp/study/project1/COMMANDPROMPT_C/Debug/task4_output_v1.txt");
	std::string date2Task4;

	while (getline(file2Task4, date2Task4)) {
		//std::cout << date2Task4 << '\n';
		if (date2Task4.length() > 6) date2Task4.erase(5);
		intdate2Task4 = atof(date2Task4.c_str());
	}
	file2Task4.close();

	if (intdate1Task4 != intdate2Task4) {
		std::cout << "Here4\n";
		checkF = false;
	}

	//5
	std::ifstream stream{ "task5_output_v1.bin" };
	std::string file1{ std::istreambuf_iterator<char>(stream),
					  std::istreambuf_iterator<char>() };

	stream = std::ifstream{ "D:/cpp/study/project1/COMMANDPROMPT_C/Debug/task5_output_v1.bin" };
	std::string file2{ std::istreambuf_iterator<char>(stream),
					  std::istreambuf_iterator<char>() };
	if (!(file1 == file2)) {
		std::cout << "Here5\n";
		checkF = false;
	}

	//6
	std::ifstream file1Task6("task6_output_v1.txt");
	std::string date1Task6;
	std::string task1S = "";
	int count1 = 0;
	while (getline(file1Task6, date1Task6)) {
		//std::cout << date1Task6 << '\n';
		task1S = date1Task6;
		count1++;
	}
	file1Task6.close();

	std::ifstream file2Task6("D:/cpp/study/project1/COMMANDPROMPT_C/Debug/task6_output_v1.txt");
	std::string date2Task6;
	std::string task2S = "";
	int count2 = 0;
	while (getline(file2Task6, date2Task6)) {
		task2S = date2Task6;
		count2++;
	}
	file2Task6.close();

	if (task2S != task1S || count1 != count2) {
		std::cout << "Here6\n";
		checkF = false;
	}

	//7
	std::ifstream file1Task7("task7_output_v1.txt");
	std::string date1Task7;
	std::string task12S = "";
	
	while (getline(file1Task7, date1Task7)) {
		//std::cout << date1Task7 << '\n';
		task12S = date1Task7;
		
	}
	file1Task7.close();

	std::ifstream file2Task7("D:/cpp/study/project1/COMMANDPROMPT_C/Debug/task7_output_v1.txt");
	std::string date2Task7;
	std::string task22S = "";
	
	while (getline(file2Task7, date2Task7)) {
		//std::cout << date2Task7 << '\n';
		task22S = date2Task7;
		
	}
	file2Task7.close();

	if (task22S != task12S ) {
		std::cout << "Here7\n";
		checkF = false;
	}

	std::cout << "\n\n\tChecking if all results are the same...\n\n";
	Sleep(5 * 1000);

	if (checkF) std::cout << "Okay\n";
	else std::cout << "Not Okay\n";

	return 0;
}