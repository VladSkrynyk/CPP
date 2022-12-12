#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include "COMMANDPROMPT.h"

/*
* Функція яка приймає з командного рядка один цілий аргумент і виводить його квадрат.
* для того щоб порахувати кількіть можливих параметрів будемо використовувати функція яка є в класі string, а саме find()
* метод використовується для пошуку першого входження підрядка у вказаному рядку, який викликається.
* Також перевіряється чи не є користувацький параметр нулем, якщо так, то виводиться інше повідомлення про помилку.
*
* Для того щоб перевірити коректність файлу з данними створимо змінну int count i будемо збільшувати її в циклі де рахуємо
* кількість стрічок. Відповідно якщо count не дорівнює 1, виводимо повідомлення про помилку.
* Якщо все коректно то створює файл з назвою task1_output_v1.txt в який записується результат роботи функції.
*
* size_t find (const string& str, size_t pos = 0) --- функція використовується для пошуку першого входження підрядка у 
* вказаному рядку, який викликається. Він повертає індекс першого входження підрядка в рядок із заданої початкової позиції. 
* Стандартне значення початкової позиції – 0.
* 
* const char* c_str() const --- метод перетворює рядок на масив символів з нульовим символом '\0' у кінці.
* 
* int atoi(const char strn) --- функція приймає рядковий параметр, який містить цілі значення, і перетворює переданий рядок 
* у ціле значення.
* 
* double atof(const char* str) --- функція аналогічна до atoi тільки може перетворювати стрічку в дійсне число.
*/
int task1(std::string option) {
	if (option == "1") {
		std::string userInputSTR = "";
				
		std::cout << "Input => ";
		std::getline(std::cin, userInputSTR);

		if (userInputSTR.find(' ') != std::string::npos || userInputSTR == "") {
			std::cout << "Incorrect number of arguments!\n";
			return -1;
		}
		else {
			int userInputINT = atoi(userInputSTR.c_str());

			std::cout << "Result -> " << userInputINT * userInputINT << '\n';
		}

		return 0;
	}
	else if (option == "2") {
		std::string dateFile;
		std::ifstream file("task1_input_v1.txt");
		int count = 0;
		int userInputINT;
		while (getline(file, dateFile)) {
			count++;
			userInputINT = atoi(dateFile.c_str());
			//std::cout << dateFile << "\n";
		}
		file.close();

		if (count != 1) {
			std::cout << "Incorrect date in file\n";
			return -1;
		}
		else {

			std::ofstream fileW("task1_output_v1.txt");
			std::cout << "File `task1_output_v1.txt` was successufuly created!\n";

			fileW << userInputINT * userInputINT;
			fileW.close();

			return 0;
		}	
	}
	else {
		std::cout << "There are no such options like :" << option << '\n';
		return -1;
	}
}

/*
* Функція яка приймає з командного рядка 3 дійсних аргументи і виводить їх середнє гармонічне. Для того щоб підрахувати
* кількість аргументів які ввів користувач будемо використовувати метод string а саме метод count(), який повертає,
* кількість входжень даного символа з стрічку. Таким чином якщо count не буде дорівнювати 3, це буде означати що кількість 
* аргуметів які ввів користувач не відповідає умові, в такому разі будемо виводити повідомлення про помилку.
*
* Аналогічно до попереднього завдання будемо перевіряти коректність файлу з данними.
* Якщо все коректно то створює файл з назвою task2_output_v1.txt в який записується результат роботи функції.
*
*/
int task2(std::string option) {
	if (option == "1") {
		std::string userInputSTR = "";

		std::cout << "Input => ";
		std::getline(std::cin, userInputSTR);

		if (std::count(userInputSTR.begin(), userInputSTR.end(), ' ') != 2 || userInputSTR == "") {
			std::cout << "Incorrect number of arguments!\n";
			return -1;
		}
		else {
			std::string temp = "";
			std::string temp1 = "";
			std::string temp2 = "";
			std::string temp3 = "";
			
			int count = 0;
			for (int i = 0; i < (int)userInputSTR.size(); i++) {
				if (userInputSTR[i] != ' ') {
					temp += userInputSTR[i];
			    }
			    else {
					count++;
			        //std::cout << temp << "\n";
			        if (count == 1) temp1 = temp;
			        else if (count == 2) temp2 = temp;            
			        temp = "";
			    }
			}
			count++;
			//std::cout << "Test " << count << "\n";
			if (count == 3) temp3 = temp;
			else {
				std::cout << "Incorrect number of arguments!\n";
				return -1;
			}

			float userInputINT1 = atof(temp1.c_str());
			float userInputINT2 = atof(temp2.c_str());
			float userInputINT3 = atof(temp3.c_str());

			std::cout << "Result -> " << 3.0 / (1.0 / userInputINT1 + 1.0 / userInputINT2 + 1.0 / userInputINT3) << '\n';
		}
		return 0;
	}
	else if (option == "2") {

		std::string dateFile;
		std::ifstream file("task2_input_v1.txt");
		int count = 0;
		int userInputINT1;
		int userInputINT2;
		int userInputINT3;
		while (getline(file, dateFile)) {
			count++;
			if (count == 1) userInputINT1 = atoi(dateFile.c_str());
			if (count == 2) userInputINT2 = atoi(dateFile.c_str());
			if (count == 3) userInputINT3 = atoi(dateFile.c_str());
			
			//std::cout << dateFile << "\n";
		}
		file.close();

		if (count != 3) {
			std::cout << "Incorrect date in file\n";
			return -1;
		}

		//std::cout << "Test : " << userInputINT1 << " " << userInputINT2 << " " << userInputINT3 << "\n";
		std::ofstream fileW("task2_output_v1.txt");
		std::cout << "File task2_output_v1.txt` was successufuly created!\n";

		fileW << 3.0 / (1.0 / userInputINT1 + 1.0 / userInputINT2 + 1.0 / userInputINT3);
		fileW.close();

		return 0;
	}
	else {
		std::cout << "There are no such options like :" << option << '\n';
		return -1;
	}
}

/*
* Функція яка примає з командного рядка назву файлу і повертає кількість стрічок в файлі. Будемо рахувати кількість рядків
* в файлі в циклі while.
*
* Якщо відбувається ввід данних з файлу, то створюється файл task3_output_v1.txt в який записується результат роботи програми.
*/
int task3(std::string option) {
	if (option == "1") {
		std::string userInputSTR;
		std::cout << "Input => ";
		std::getline(std::cin, userInputSTR);

		std::string dateFile;
		std::ifstream file(userInputSTR);

		if (!file.good()) {
			std::cout << "Incorrect name of file\n";
			return -1;
		}

		int count = 0;
		while (getline(file, dateFile)) {
			count++;
			//std::cout << dateFile << "\n";
		}
		file.close();

		std::cout << "Result => " << count << '\n';
		return 0;
	}
	else if (option == "2") {
		std::string dateFile;
		std::ifstream file("task3_input_v1.txt");

		if (!file.good()) {
			std::cout << "Incorrect name of file\n";
			return -1;
		}

		int count = 0;
		while (getline(file, dateFile)) {
			count++;
			//std::cout << dateFile << "\n";
		}
		file.close();

		std::ofstream fileW("task3_output_v1.txt");
		std::cout << "File `task3_output_v1.txt` was successufuly created!\n";

		fileW << count;
		fileW.close();

		return 0;
	}
	else {
		std::cout << "There are no such options like :" << option << '\n';
		return -1;
	}
}

/*
* Функція яка приймає я командного рядка спочатку кількість текстових файлів, а потім назву кожного файлу.
* Потім для кожного файлу рахується кількість символів та кількість рядків, змінні int countSymbol, int countRow відповідні.
*
* Функція при роботі з файлом з данними працює аналогічно.
* Якщо все коректно то створюються файли з відповідною назвою(назва файлу та саме, тільки input міняється
* на output) в який записується результат роботи функції.
*
*/
int task4(std::string option) {
	if (option == "1") {
		int n;
		std::string str;
		std::cout << "Input number of files: ";
		std::getline(std::cin, str);

		n = std::stoi(str);

		char** array_files = (char**)malloc(n * sizeof(char*));
		for (int i = 0; i < n; i++)
			array_files[i] = (char*)malloc(50 * sizeof(char));

		for (int i = 0; i < n; i++) {
			std::cout << "Input filename of " <<  i + 1 << " file: ";
			std::cin >> array_files[i];
		}

		for (int i = 0; i < n; i++) {
			std::string dateFile;
			std::ifstream file(array_files[i]);

			if (!file.good()) {
				std::cout << "Incorrect name of file\n";
				return -1;
			}

			int countRow = 0;
			int countSymbol = 0;
			while (getline(file, dateFile)) {
				countRow++;
				countSymbol += dateFile.length();
				//std::cout << dateFile << "\n";
			}
			file.close();
			//std::cout << "Test1 : " << countRow << " Test2 : " << countSymbol << '\n';
			//printf("Medium density in file %s => %f \n", array_files[i], (double)countSymbol / countRow);
			std::cout << "Medium density in file " << array_files[i] << " => " << (double)countSymbol / countRow << "\n";
		}
		return 0;
	}
	else if (option == "2") {
		std::vector<std::string> array_files = { "task4_input_v1.txt", "task4_input_v2.txt","task4_input_v3.txt" };
		std::vector<std::string> array_output_files = { "task4_output_v1.txt", "task4_output_v2.txt","task4_output_v3.txt" };
		
		for (int i = 0; i < 3; i++) {
			std::string dateFile;
			std::ifstream file(array_files[i]);

			if (!file.good()) {
				std::cout << "Incorrect name of file\n";
				return -1;
			}

			int countRow = 0;
			int countSymbol = 0;
			while (getline(file, dateFile)) {
				countRow++;
				countSymbol += dateFile.length();
				//std::cout << dateFile << "\n";
			}
			file.close();
			
			//std::cout << "Test1 : " << countRow << " Test2 : " << countSymbol << '\n';
			//printf("Medium density in file %s => %f \n", array_files[i], (double)countSymbol / countRow);
			std::ofstream fileW(array_output_files[i]);
			std::cout << "File " << array_output_files[i] << " was successufuly created!\n";
			//fileW << "Medium density in file is = > ";
			fileW << (double)countSymbol / countRow;
			fileW.close();
		}
		return 0;
	}
	else {
		std::cout << "There are no such options like :" << option << '\n';
		return -1;
	}
}

/*
* Функція яка приймає з командного рядка стрічку вигляду: -filename name -rows rows, та створює файл з назвою name і заповнює
* його цілими числами від 0 до rows. Аналогічно до попередніх завдань будемо перевіряти кількість аргументів які ввів користувач.
* та в циклі будемо перевіряти чи правильно користувач ввів 1 та 3 параметр вказаної в умові стрічки.
*
* Функція при роботі з файлом з данними працює аналогічно.
* Якщо все коректно то створює файл з назвою task5_output_v1.txt в який записується результат роботи функції.
*
*/
int task5(std::string option) {
	if (option == "1") {
		std::string userInputSTR = "";

		std::cout << "Input => ";
		std::getline(std::cin, userInputSTR);

		if (std::count(userInputSTR.begin(), userInputSTR.end(), ' ') != 3 || userInputSTR == "") {
			std::cout << "Incorrect input!\nYour input should be like this: -filename name -rows rows\n";
			return -1;
		}
		else {
			std::string temp = "";
			std::string temp1 = "";
			std::string temp2 = "";
			std::string temp3 = "";
			int temp4 = 0;

			int count = 0;
			for (int i = 0; i < (int)userInputSTR.size(); i++) {
				if (userInputSTR[i] != ' ') {
					temp += userInputSTR[i];
				}
				else {
					count++;
					if (count == 1 && temp == "-filename") {
						temp1 = temp;
					}
					else if (temp != "-filename" && count ==1) {
						std::cout << "Incorrect input!\nYour input should be like this: -filename name -rows rows\n";
						return -1;
					}

					if (count == 2) {
						temp2 = temp;
					}

					if (count == 3 && temp == "-rows") {
						temp3 = temp;
					}
					else if (temp != "-rows" && count == 3) {
						std::cout << "Incorrect input!\nYour input should be like this: -filename name -rows rows\n";
						return -1;
					}

					
					temp = "";
				}
			}
			count++;
			//std::cout << "Test " << count << "\n";
			if (count == 4) temp4 = atoi(temp.c_str());
			else {
				std::cout << "Incorrect number of arguments!\n";
				return -1;
			}
			//std::cout << "Your input was: " << temp1 << " " << temp2 << " " << temp3 << " " << temp4  << '\n';

			std::ofstream file(temp2);

			if (!file.good()) {
				std::cout << "File can't be created\n";
				return -1;
			}
			for (int i = 0; i < temp4; i++) {
				file.write(reinterpret_cast<const char*>(&i), sizeof(i));
			}

			file.close();
			return 0;
		}	
	}
	else if (option == "2") {
		std::string dateFile;
		std::ifstream file("task5_input_v1.txt");

		std::string Date;
		int count = 0;
		while (getline(file, dateFile)) {
			count++;
			Date = dateFile;
			//std::cout << dateFile << "\n";
		}
		file.close();

		if (count != 1) {
			std::cout << "Incorrect date in file!\n";
			return -1;
		}
		//std::cout << "Test => " << Date << '\n';

		if (std::count(Date.begin(), Date.end(), ' ') != 3 || Date == "") {
			std::cout << "Incorrect input!\nYour input should be like this: -filename name -rows rows\n";
			return -1;
		}
		else {
			std::string temp = "";
			std::string temp1 = "";
			std::string temp2 = "";
			std::string temp3 = "";
			int temp4 = 0;

			int count = 0;
			for (int i = 0; i < (int)Date.size(); i++) {
				if (Date[i] != ' ') {
					temp += Date[i];
				}
				else {
					count++;
					if (count == 1 && temp == "-filename") {
						temp1 = temp;
					}
					else if (temp != "-filename" && count == 1) {
						std::cout << "Incorrect input!\nYour input should be like this: -filename name -rows rows\n";
						return -1;
					}

					if (count == 2) {
						temp2 = temp;
					}

					if (count == 3 && temp == "-rows") {
						temp3 = temp;
					}
					else if (temp != "-rows" && count == 3) {
						std::cout << "Incorrect input!\nYour input should be like this: -filename name -rows rows\n";
						return -1;
					}
					temp = "";
				}
			}
			count++;
			//std::cout << "Test " << count << "\n";
			if (count == 4) temp4 = atoi(temp.c_str());
			else {
				std::cout << "Incorrect number of arguments!\n";
				return -1;
			}
			//std::cout << "Your input was: " << temp1 << " " << temp2 << " " << temp3 << " " << temp4  << '\n';

			std::ofstream file(temp2);
			std::cout << "File " << temp2 << " was successufuly created!\n";

			if (!file.good()) {
				std::cout << "File can't be created\n";
				return -1;
			}
			for (int i = 0; i < temp4; i++) {
				file.write(reinterpret_cast<const char*>(&i), sizeof(i));
			}

			file.close();
			return 0;
		}
	}
	else {
		std::cout << "There are no such options like :" << option << '\n';
		return -1;
	}
}

/*
* Функція яка приймає з командного рядка стрічку вигляду: -filename name -rows rows -cols cols, та створює відповідний
* текстовий файл з назвою name, що містить вказану кількість рядків rows заповнену cols нулями через табуляцію.
*
* Функція при роботі з файлом з данними працює аналогічно.
* Якщо все коректно то створює файл з назвою task6_output_v1.txt в який записується результат роботи функції.
*
*/
int task6(std::string option) {
	if (option == "1") {
		std::string userInputSTR = "";

		std::cout << "Input => ";
		std::getline(std::cin, userInputSTR);

		if (std::count(userInputSTR.begin(), userInputSTR.end(), ' ') != 5 || userInputSTR == "") {
			std::cout << "Incorrect input!\nYour input should be like this: -filename name -rows rows -cols cols\n";
			return -1;
		}
		else {
			std::string temp = "";
			std::string temp1 = "";
			std::string temp2 = "";
			std::string temp3 = "";
			int temp4 = 0;
			std::string temp5 = "";
			int temp6 = 0;

			int count = 0;
			for (int i = 0; i < (int)userInputSTR.size(); i++) {
				if (userInputSTR[i] != ' ') {
					temp += userInputSTR[i];
				}
				else {
					count++;
					if (count == 1 && temp == "-filename") {
						temp1 = temp;
					}
					else if (temp != "-filename" && count == 1) {
						std::cout << "Incorrect input!\nYour input should be like this: -filename name -rows rows -cols cols\n";
						return -1;
					}

					if (count == 2) {
						temp2 = temp;
					}

					if (count == 3 && temp == "-rows") {
						temp3 = temp;
					}
					else if (temp != "-rows" && count == 3) {
						std::cout << "Incorrect input!\nYour input should be like this: -filename name -rows rows -cols cols\n";
						return -1;
					}

					if (count == 4) temp4 = atoi(temp.c_str());

					if (count == 5 && temp == "-cols") {
						temp3 = temp;
					}
					else if (temp != "-cols" && count == 5) {
						std::cout << "Incorrect input!\nYour input should be like this: -filename name -rows rows -cols cols\n";
						return -1;
					}
					temp = "";
				}
			}
			count++;
			//std::cout << "Test " << count << "\n";
			if (count == 6) temp6 = atoi(temp.c_str());
			else {
				std::cout << "Incorrect number of arguments!\n";
				return -1;
			}
			//std::cout << "Your input was: " << temp1 << " " << temp2 << " " << temp3 << " " << temp4  << 
			//	" " << temp5 << " " << temp6 << '\n';

			std::ofstream fileW(temp2);
			if (!fileW.good()) {
				std::cout << "File can't be created!\n";
				return -1;
			}

			std::cout << "File created successfully!\n";

			for (int i = 0; i < temp4; i++) {
				for (int j = 0; j < temp6; j++) {
					fileW << 0;
					fileW << "\t";
				}
				fileW << "\n";
			}

			fileW.close();
			return 0;
		}
	}
	else if (option == "2") {
		std::string dateFile;
		std::ifstream file("task6_input_v1.txt");

		std::string Date;
		int count = 0;
		while (getline(file, dateFile)) {
			count++;
			Date = dateFile;
			//std::cout << dateFile << "\n";
		}
		file.close();

		if (count != 1) {
			std::cout << "Incorrect date in file!\n";
			return -1;
		}
		//std::cout << "Test => " << Date << '\n';

		if (std::count(Date.begin(), Date.end(), ' ') != 5 || Date == "") {
			std::cout << "Incorrect input!\nYour input should be like this: -filename name -rows rows -cols cols\n";
			return -1;
		}
		else {
			std::string temp = "";
			std::string temp1 = "";
			std::string temp2 = "";
			std::string temp3 = "";
			int temp4 = 0;
			std::string temp5 = "";
			int temp6 = 0;

			int count = 0;
			for (int i = 0; i < (int)Date.size(); i++) {
				if (Date[i] != ' ') {
					temp += Date[i];
				}
				else {
					count++;
					if (count == 1 && temp == "-filename") {
						temp1 = temp;
					}
					else if (temp != "-filename" && count == 1) {
						std::cout << "Incorrect input!\nYour input should be like this: -filename name -rows rows\n";
						return -1;
					}

					if (count == 2) {
						temp2 = temp;
					}

					if (count == 3 && temp == "-rows") {
						temp3 = temp;
					}
					else if (temp != "-rows" && count == 3) {
						std::cout << "Incorrect input!\nYour input should be like this: -filename name -rows rows\n";
						return -1;
					}

					if (count == 4) temp4 = atoi(temp.c_str());

					if (count == 5 && temp == "-cols") {
						temp5 = temp;
					}
					else if (temp != "-cols" && count == 5) {
						std::cout << "Incorrect input!\nYour input should be like this: -filename name -rows rows\n";
						return -1;
					}

					temp = "";
				}
			}
			count++;
			//std::cout << "Test " << count << "\n";
			if (count == 6) temp6 = atoi(temp.c_str());
			else {
				std::cout << "Incorrect number of arguments!\n";
				return -1;
			}
			//std::cout << "Your input was: " << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << " "
			//	<< temp5 << " " << temp6 << '\n';

			std::ofstream fileW(temp2);
			if (!fileW.good()) {
				std::cout << "File can't be created!\n";
				return -1;
			}

			std::cout << "File " << temp2 << " was created successfully!\n";

			for (int i = 0; i < temp4; i++) {
				for (int j = 0; j < temp6; j++) {
					fileW << 0;
					fileW << "\t";
				}
				fileW << "\n";
			}

			fileW.close();
			return 0;
		}
	}
	else {
		std::cout << "There are no such options like :" << option << '\n';
		return -1;
	}
}

/*
* Функція яка приймає з командного рядка стрічку вигляду: -filename1 name1 -filename2 name2 -rows rows, останній аргумент не є
* обовязковим, та порівнює чи співпадає в даних двох файлах перші rows рядків з точністю до пробілів,
* якщо rows не вказаний – файли порівнюються повністю всі рядки.
*
* Функція при роботі з файлом з данними працює аналогічно.
* Якщо все коректно то створює файл з назвою task7_output_v1.txt в який записується результат роботи функції.
*
*/
int task7(std::string option) {
	if (option == "1") {

		std::string userInputSTR = "";

		std::cout << "Input => ";
		std::getline(std::cin, userInputSTR);

		/*if (std::count(userInputSTR.begin(), userInputSTR.end(), ' ') != 5 || userInputSTR == "") {
			std::cout << "Incorrect input!\nYour input should be like this: -filename name -rows rows -cols cols\n";
			return -1;
		}*/
		if (std::count(userInputSTR.begin(), userInputSTR.end(), ' ') == 5 || std::count(userInputSTR.begin(), userInputSTR.end(), ' ') == 4) {
			std::string temp = "";
			std::string temp1 = "";
			std::string temp2 = "";
			std::string temp3 = "";
			std::string temp4 = "";
			std::string temp5 = "";
			int temp6 = NULL;

			int count = 0;
			for (int i = 0; i < (int)userInputSTR.size(); i++) {
				if (userInputSTR[i] != ' ') {
					temp += userInputSTR[i];
				}
				else {
					count++;
					if (count == 1 && temp == "-filename1") {
						temp1 = temp;
					}
					else if (temp != "-filename1" && count == 1) {
						std::cout << "Incorrect input!\nYour input should be like this: -filename1 name1 -filename2 name2 -rows rows\n";
						return -1;
					}

					if (count == 2) {
						temp2 = temp;
					}

					if (count == 3 && temp == "-filename2") {
						temp3 = temp;
					}
					else if (temp != "-filename2" && count == 3) {
						std::cout << "Incorrect input!\nYour input should be like this: -filename1 name1 -filename2 name2 -rows rows\n";
						return -1;
					}

					if (count == 4) temp4 = temp;;

					if (count == 5 && temp == "-rows") {
						temp5 = temp;
					}
					else if (temp != "-rows" && count == 5) {
						std::cout << "Incorrect input!\nYour input should be like this: -filename1 name1 -filename2 name2 -rows rows\n";
						return -1;
					}

					temp = "";
				}
			}
			count++;
			
			if (count == 6) temp6 = atoi(temp.c_str());
			else if (count >= 7) {
				std::cout << "Incorrect number of arguments!\n";
				return -1;
			}

			std::cout << "Your input was: " << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << " "
				<< temp5 << " " << temp6 << '\n';

			if (temp6 == NULL) {
				
				std::string dateFile1;
				std::ifstream file1(temp2);
				std::vector<std::string> dateFilename1;
				if (!file1.good()) {
					std::cout << "Incorrect filename\n";
					return -1;
				}
				int count1 = 0;
				while (getline(file1, dateFile1)) {
					dateFilename1.push_back(dateFile1);
					count1++;
					//std::cout <<"Test 1 => " << dateFile1 << "\n";
				}
				//std::cout << "Lines => " << count1 << '\n';

				file1.close();


				std::string dateFile2;
				std::ifstream file2(temp4);
				std::vector<std::string> dateFilename2;
				if (!file2.good()) {
					std::cout << "Incorrect filename\n";
					return -1;
				}
				int count2 = 0;
				while (getline(file2, dateFile2)) {
					count2++;
					dateFilename2.push_back(dateFile2);
					//std::cout << "Test 2 => " << dateFile2 << "\n";
				}
				//std::cout << "Lines => " << count2 << '\n';

				file2.close();

				if (count1 != count2) {
					std::cout << "Not equal content in files";
					return -1;
				}

				for (int i = 0; i < count1; i++) {
					if (dateFilename1[i] != dateFilename2[i]) {
						std::cout << "Not equal content in files\n";
						return -1;
					}
				}

				std::cout << "The content in the files is the same\n";

				return 0;
			}
			else {
				std::string dateFile1;
				std::ifstream file1(temp2);
				std::vector<std::string> dateFilename1;
				if (!file1.good()) {
					std::cout << "Incorrect filename\n";
					return -1;
				}
				int count1 = 0;
				while (getline(file1, dateFile1)) {
					dateFilename1.push_back(dateFile1);
					count1++;
					//std::cout <<"Test 1 => " << dateFile1 << "\n";
				}
				//std::cout << "Lines => " << count1 << '\n';

				file1.close();


				std::string dateFile2;
				std::ifstream file2(temp4);
				std::vector<std::string> dateFilename2;
				if (!file2.good()) {
					std::cout << "Incorrect filename\n";
					return -1;
				}
				int count2 = 0;
				while (getline(file2, dateFile2)) {
					count2++;
					dateFilename2.push_back(dateFile2);
					//std::cout << "Test 2 => " << dateFile2 << "\n";
				}
				//std::cout << "Lines => " << count2 << '\n';

				file2.close();

				

				for (int i = 0; i < temp6; i++) {
					if (dateFilename1[i] != dateFilename2[i]) {
						std::cout << "Not equal content in files\n";
						return -1;
					}
				}
				std::cout << "The content in the files is the same\n";

				return 0;
			}
		}
		else {
			std::cout << "Incorrect input!\nYour input should be like this: -filename1 name1 -filename2 name2 -rows rows\n";
			return -1;
		}
	}
	else if (option == "2") {
		std::string userInputSTR = "";
		std::string InputDate;
		std::ifstream InputFile("task7_input_v3.txt");
		int countM = 0;
		while (getline(InputFile, InputDate)) {
			countM++;
			userInputSTR = InputDate;
			//std::cout << "Test 2 => " << dateFile2 << "\n";
		}
		InputFile.close();
		if (countM != 1) {
			std::cout << "Incorrect date in file\n";
			return -1;
		}

		/*if (std::count(userInputSTR.begin(), userInputSTR.end(), ' ') != 5 || userInputSTR == "") {
			std::cout << "Incorrect input!\nYour input should be like this: -filename name -rows rows -cols cols\n";
			return -1;
		}*/
		if (std::count(userInputSTR.begin(), userInputSTR.end(), ' ') == 5 || std::count(userInputSTR.begin(), userInputSTR.end(), ' ') == 4) {
			std::string temp = "";
			std::string temp1 = "";
			std::string temp2 = "";
			std::string temp3 = "";
			std::string temp4 = "";
			std::string temp5 = "";
			int temp6 = NULL;

			int count = 0;
			for (int i = 0; i < (int)userInputSTR.size(); i++) {
				if (userInputSTR[i] != ' ') {
					temp += userInputSTR[i];
				}
				else {
					count++;
					if (count == 1 && temp == "-filename1") {
						temp1 = temp;
					}
					else if (temp != "-filename1" && count == 1) {
						std::cout << "Incorrect input!\nYour input should be like this: -filename1 name1 -filename2 name2 -rows rows\n";
						return -1;
					}

					if (count == 2) {
						temp2 = temp;
					}

					if (count == 3 && temp == "-filename2") {
						temp3 = temp;
					}
					else if (temp != "-filename2" && count == 3) {
						std::cout << "Incorrect input!\nYour input should be like this: -filename1 name1 -filename2 name2 -rows rows\n";
						return -1;
					}

					if (count == 4) temp4 = temp;;

					if (count == 5 && temp == "-rows") {
						temp5 = temp;
					}
					else if (temp != "-rows" && count == 5) {
						std::cout << "Incorrect input!\nYour input should be like this: -filename1 name1 -filename2 name2 -rows rows\n";
						return -1;
					}

					temp = "";
				}
			}
			count++;

			if (count == 6) temp6 = atoi(temp.c_str());
			else if (count >= 7) {
				std::cout << "Incorrect number of arguments!\n";
				return -1;
			}

			std::cout << "Date in file: " << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << " "
				<< temp5 << " " << temp6 << '\n';


			if (temp6 == NULL) {

				std::string dateFile1;
				std::ifstream file1(temp2);
				std::vector<std::string> dateFilename1;
				if (!file1.good()) {
					std::cout << "Incorrect filename\n";
					return -1;
				}
				int count1 = 0;
				while (getline(file1, dateFile1)) {
					dateFilename1.push_back(dateFile1);
					count1++;
					//std::cout <<"Test 1 => " << dateFile1 << "\n";
				}
				//std::cout << "Lines => " << count1 << '\n';

				file1.close();


				std::string dateFile2;
				std::ifstream file2(temp4);
				std::vector<std::string> dateFilename2;
				if (!file2.good()) {
					std::cout << "Incorrect filename\n";
					return -1;
				}
				int count2 = 0;
				while (getline(file2, dateFile2)) {
					count2++;
					dateFilename2.push_back(dateFile2);
					//std::cout << "Test 2 => " << dateFile2 << "\n";
				}
				//std::cout << "Lines => " << count2 << '\n';

				file2.close();

				if (count1 != count2) {
					std::ofstream fileF("task7_output_v1.txt");
					std::cout << "File `task7_output_v1.txt` was successufuly created!\n";

					fileF << "Not equal content in files\n";
					fileF.close();
					return -1;
				}

				for (int i = 0; i < count1; i++) {
					if (dateFilename1[i] != dateFilename2[i]) {
						std::ofstream fileF("task7_output_v1.txt");
						std::cout << "File `task7_output_v1.txt` was successufuly created!\n";

						fileF << "Not equal content in files\n";
						fileF.close();

						return -1;
					}
				}

				std::ofstream fileF("task7_output_v1.txt");
				std::cout << "File `task7_output_v1.txt` was successufuly created!\n";

				fileF << "The content in the files is the same\n";
				fileF.close();
				return 0;
			}
			else {
				std::string dateFile1;
				std::ifstream file1(temp2);
				std::vector<std::string> dateFilename1;
				if (!file1.good()) {
					std::cout << "Incorrect filename\n";
					return -1;
				}
				int count1 = 0;
				while (getline(file1, dateFile1)) {
					dateFilename1.push_back(dateFile1);
					count1++;
					//std::cout <<"Test 1 => " << dateFile1 << "\n";
				}
				//std::cout << "Lines => " << count1 << '\n';

				file1.close();


				std::string dateFile2;
				std::ifstream file2(temp4);
				std::vector<std::string> dateFilename2;
				if (!file2.good()) {
					std::cout << "Incorrect filename\n";
					return -1;
				}
				int count2 = 0;
				while (getline(file2, dateFile2)) {
					count2++;
					dateFilename2.push_back(dateFile2);
					//std::cout << "Test 2 => " << dateFile2 << "\n";
				}
				//std::cout << "Lines => " << count2 << '\n';

				file2.close();



				for (int i = 0; i < temp6; i++) {
					if (dateFilename1[i] != dateFilename2[i]) {
						std::ofstream fileF("task7_output_v1.txt");
						std::cout << "File `task7_output_v1.txt` was successufuly created!\n";

						fileF << "Not equal content in files\n";
						fileF.close();
						return -1;
					}
				}

				std::ofstream fileF("task7_output_v1.txt");
				std::cout << "File `task7_output_v1.txt` was successufuly created!\n";

				fileF << "The content in the files is the same\n";
				fileF.close();

				return 0;
			}
		}
		else {
			std::cout << "There are no such options like :" << option << '\n';
			return -1;
		}
	}
	else {
		std::cout << "There are no such options like :" << option << '\n';
		return -1;
	}
}
