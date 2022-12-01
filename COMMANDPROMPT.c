#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "COMMANDPROMPT.h"

/*
* Функція яка приймає з командного рядка один цілий аргумент і виводить його квадрат.
* для того щоб порахувати кількіть можливих параметрів будемо рахувати ті символи що знаходяться між пробілами,
* відповідно якщо така кількість перевищує 1, то виводиться відповідне повідомлення про помилку.
* Також перевіряється чи не є користувацький параметр нулем, якщо так, то виводиться інше повідомлення про помилку.
* 
* Для того щоб перевірити коректність файлу з данними створимо змінну int perhapsInput = NULL і присвоємо їй значення
* якщо рядків в файлі буде більше одного, відповідно якщо після читання даних з файлу perhapsInput не дорівнює NULL завершує роботу
* Якщо все коректно то створює файл з назвою task1_output_v1.txt в який записується результат роботи функції.
* 
* strtok(char *str, const char *delim) --- функція яка приймає 2 параметри str та delim. 
* Функція розбиває рядок str на серію так званих токенів за допомогою роздільника delim.
* 
* strol(const char *str, char **endptr, int base) --- функція перетворює рядок str на ціле число за базою base. 
* Функція працює, ігноруючи будь-які пробіли на початку рядка, перетворюючи наступні символи на ціле число 
* та зупиняючись, коли зустрічається перший нецілий символ.
*/
int task1(char option[]) {
	if (option[0] == '1') {
		char str[50] = "";
		printf("Input => ");
		fgets(str, 50, stdin);
		str[strlen(str) - 1] = '\0';

		//printf("Your input => %s %s", str, option);

		char* token = strtok(str, " ");

		int userInput;
		int count = 0;
		while (token != NULL) {
			count++;
			//printf("%s\n", token); 
			char* ptr;
			userInput = strtol(token, &ptr, 10);
			token = strtok(NULL, " ");
		}

		if (count != 1) {
			printf("Incorrect number of arguments!\n");
			return -1;
		}
		else {
			if (userInput == 0) {
				printf("Incorrect argument!\n");
				return -1;
			}
			printf("Result -> %d\n", userInput * userInput);
			return 0;
		}
	}
	else if (option[0] == '2') {
		FILE* file;
		errno_t err;
		char ch;

		// Opening file in reading mode
		err = fopen_s(&file, "task1_input_v1.txt", "r");

		if (err != 0) {
			printf("file can't be opened \n");
			return -1;
		}

		int count = 0;

		while (!feof(file)) {
			ch = fgetc(file);
			//printf("%c", ch);
			if (ch == '\n') count++;
		}
		fclose(file);

		if (count != 1) {
			printf("Incorrect number of arguments!\n");
			return -1;
		}
		else {
			FILE* file;
			char buffer[255];

			// Opening file in reading mode
			fopen_s(&file, "task1_input_v1.txt", "r");
			int userInput1 = 0;
			int perhapsInput = NULL;
			char* test = "";
			int count = 0;
			while (fgets(buffer, 255, file)) {
				//printf("%s\n", buffer);
				if (count == 0) test = buffer;
				else perhapsInput = 1;
				count++;
			}
			fclose(file);
			char* ptr;
			userInput1 = strtol(test, &ptr, 10);
			//printf("Rows => %d", userInput1);

			if (perhapsInput != NULL) {
				printf("Incorrect number of arguments in file!\n");
				return -1;
			}
			else {
				if (userInput1 == 0) {
					printf("Incorrect argument!\n");
					return -1;
				}
				FILE* fptr;
				fopen_s(&fptr, "task1_output_v1.txt", "w");
				printf("File `task1_output_v1.txt` was successufuly created!\n");


				fprintf(fptr, "%d\n", userInput1 * userInput1);
				fclose(fptr);
				//printf("Result -> %d\n", userInput1 * userInput1);
				return 0;
			}
		}
	}
	else {
		printf("There are no such options like : %s\n", option);
		return -1;
	}
}

/*
* Функція яка приймає з командного рядка 3 дійсних аргументи і виводить їх середнє гармонічне. Для того щоб підрахувати 
* кількість аргументів які ввів користувач створимо змінну int count і в циклів який розбиває стрічку яку ввів користувач будемо
* збільшувати значення count на 1. Таким чином якщо count не буде дорівнювати 3, це буде означати що кількість аргуметів які
* ввів користувач не відповідає умові, в такому разі будемо виводити повідомлення про помилку.
* 
* Аналогічно до попереднього завдання будемо перевіряти коректність файлу з данними.
* Якщо все коректно то створює файл з назвою task2_output_v1.txt в який записується результат роботи функції.
* 
* особливості компілятора Visual Studio трохи змінюють кількість параметрів функції strtof, але принцип роботи
* функції залишається незмінним.
* strtof(const char* str, char **endptr, int base) --- функція яка перетворює str на дійсне число за базою base.
* параметр endptr це посилання на вже виділений об’єкт типу char*, значення якого встановлюється функцією до наступного 
* символу в str після числового значення.
*/
int task2(char option[]) {
	if (option[0] == '1') {
		char str[50] = "";
		printf("Input => ");
		fgets(str, 50, stdin);
		str[strlen(str) - 1] = '\0';

		//printf("Your input => %s %s", str, option);

		char* token = strtok(str, " ");

		float userInput1;
		float userInput2;
		float userInput3;
		int count = 0;
		while (token != NULL) {
			count++;
			//printf("%s\n", token);
			if (count == 1) {
				char* ptr;
				userInput1 = strtof(token, &ptr, 10);
			}
			else if (count == 2) {
				char* ptr;
				userInput2 = strtof(token, &ptr, 10);
			}
			else if (count == 3) {
				char* ptr;
				userInput3 = strtof(token, &ptr, 10);
			}
			token = strtok(NULL, " ");
		}

		if (count != 3) {
			printf("Incorrect number of arguments!\n");
			return -1;
		}
		else {
			if (userInput1 == 0 || userInput2 == 0 || userInput3 == 0) {
				printf("Incorrect argument!\n");
				return -1;
			}
			printf("Result -> %.3f\n",(float)3.0 / (1.0 / userInput1 + 1.0 / userInput2 + 1.0 / userInput3));
			return 0;
		}
	}
	else if (option[0] == '2') {
		FILE* file;
		errno_t err;
		char ch;

		// Opening file in reading mode
		err = fopen_s(&file, "task2_input_v1.txt", "r");

		if (err != 0) {
			printf("file can't be opened \n");
			return -1;
		}

		int count = 0;

		while (!feof(file)) {
			ch = fgetc(file);
			//printf("%c", ch);
			if (ch == '\n') count++;
		}
		fclose(file);

		if (count != 3) {
			printf("Incorrect number of arguments!\n");
			return -1;
		}
		else {
			FILE* file;
			char buffer[255];

			// Opening file in reading mode
			fopen_s(&file, "task2_input_v1.txt", "r");
			float userInput1 = 0;
			float userInput2 = 0;
			float userInput3 = 0;
			int perhapsInput = NULL;
			char* test1 = "";
			char* test2 = "";
			char* test3 = "";
			int count = 0;
			while (fgets(buffer, 255, file)) {
				count++;
				//printf("%s\n", buffer);
				if (count == 1) {
					char* ptr1;
					test1 = buffer;
					userInput1 = strtof(test1, &ptr1, 10);
				}
				else if (count == 2) {
					char* ptr2;
					test2 = buffer;
					userInput2 = strtof(test2, &ptr2, 10);
				}
				else if (count == 3) {
					char* ptr3;
					test3 = buffer;
					userInput3 = strtof(test3, &ptr3, 10);
				}
				else {
					perhapsInput = buffer;
				}
			}
			fclose(file);
			//printf("Test -> %f %f %f\n",userInput1, userInput2, userInput3);

			if (perhapsInput != NULL) {
				printf("Incorrect number of arguments!\n");
				return -1;
			}
			else {
				if (userInput1 == 0 || userInput2 == 0 || userInput3 == 0) {
					printf("Incorrect argument!\n");
					return -1;
				}
				FILE* fptr;
				fopen_s(&fptr, "task2_output_v1.txt", "w");
				printf("File `task2_output_v1.txt` was successufuly created!\n");
				
				fprintf(fptr, "%f\n", (float)3.0 / (1.0 / userInput1 + 1.0 / userInput2 + 1.0 / userInput3));
				fclose(fptr);
				
				return 0;
			}
		}
	}
	else {
		printf("There are no such options like : %s\n", option);
		return -1;
	}
}

/*
* Функція яка примає з командного рядка назву файлу і повертає кількість стрічок в файлі. Будемо рахувати кількість рядків
* в файлі за кількістю символів \n.
* 
* Якщо відбувається ввід данних з файлу, то створюється файл task3_output_v1.txt в який записується результат роботи програми.
*/
int task3(char option[]) {
	if (option[0] == '1') {
		char str[50] = "";
		printf("Input => ");
		fgets(str, 50, stdin);
		str[strlen(str) - 1] = '\0';

		//printf("Your input => %s", str);

		FILE* file;
		errno_t err;
		char ch;
		err = fopen_s(&file, str, "r");

		if (err != 0) {
			printf("file can't be opened \n");
			return -1;
		}

		int count = 0;
		while (!feof(file)) {
			ch = fgetc(file);
			//printf("%c", ch);
			if (ch == '\n') count++;
		}
		fclose(file);

		printf("Number of rows in file %s => %d\n", str, count);
		return 0;
	}
	else if (option[0] == '2') {
		FILE* file;
		errno_t err;
		char ch;
		err = fopen_s(&file, "task3_input_v1.txt", "r");

		if (err != 0) {
			printf("file can't be opened \n");
			return -1;
		}

		int count = 0;
		while (!feof(file)) {
			ch = fgetc(file);
			//printf("%c", ch);
			if (ch == '\n') count++;
		}
		fclose(file);

		//printf("Number of rows in file %s => %d\n", "task3_input_v1.txt", count);
		FILE* fileW;
		fopen_s(&fileW, "task3_output_v1.txt", "w");
		printf("File `task3_output_v1.txt` was successufuly created!\n");

		fprintf(file, "%d\n", count);
		fclose(fileW);

		return 0;
	}
	else {
		printf("There are no such options like : %s\n", option);
		return -1;
	}
}

/*
* Функція яка приймає я командного рядка спочатку питає кількість текстових файлів, а потім назву кожного файлу.
* Потім для кожного файлу рахується кількість символів та кількість рядків, змінні int countSymbol, int countRow відповідні.
* 
* Функція при роботі з файлом з данними працює аналогічно.
* Якщо все коректно то створюються файли з відповідною назвою(назва файлу та саме, тільки input міняється
* на output) в який записується результат роботи функції.
* 
* malloc --- метод який використовується для динамічного виділення окремого великого блоку пам’яті заданого розміру. 
* Він повертає вказівник типу void, який можна перетворити на вказівник будь-якої форми.
*/
int task4(char option[]) {
	if (option[0] == '1') {
		int n;
		char str[50] = "";
		printf("Input number of files: ");
		fgets(str, 50, stdin);

		char* ptr;
		n = strtol(str, &ptr, 10);

		char** array_files = (char**)malloc(n * sizeof(char*));
		for (int i = 0; i < n; i++)
			array_files[i] = (char*)malloc(50 * sizeof(char));

		for (int i = 0; i < n; i++) {
			printf("Input filename of %d file: ", i + 1);
			fgets(array_files[i], 50, stdin);
			array_files[i][strlen(array_files[i]) - 1] = '\0';
		}
		
		for (int i = 0; i < n; i++) {
			FILE* file;
			errno_t err;
			char ch;

			// Opening file in reading mode
			err = fopen_s(&file, array_files[i], "r");

			if (err != 0) {
				printf("file can't be opened \n");
				return -1;
			}

			int countRow = 0;
			int countSymbol = 0;
			//printf("\nContent of file %d: \n", i);
			while (!feof(file)) {
				ch = fgetc(file);
				//printf("%c", ch);
				countSymbol++;
				if (ch == '\n') countRow++;
			}
			fclose(file);
			countSymbol = countSymbol - 1 - countRow;
			//printf("Test 1 => %d\n", countSymbol);
			//printf("Test 2 => %d\n", countRow);

			printf("Medium density in file %s => %f \n", array_files[i], (double)countSymbol / countRow);
		}

		return 0;
	}
	else if (option[0] == '2') {
		char array_files[3][50] = { "task4_input_v1.txt", "task4_input_v2.txt", "task4_input_v3.txt" };
		char array_output_files[3][50] = { "task4_output_v1.txt", "task4_output_v2.txt", "task4_output_v3.txt" };

		for (int i = 0; i < 3; i++) {
			FILE* file;
			errno_t err;
			char ch;

			// Opening file in reading mode
			err = fopen_s(&file, array_files[i], "r");

			if (err != 0) {
				printf("file can't be opened \n");
				return -1;
			}

			int countRow = 0;
			int countSymbol = 0;
			//printf("\nContent of file %d: \n", i);
			while (!feof(file)) {
				ch = fgetc(file);
				//printf("%c", ch);
				countSymbol++;
				if (ch == '\n') countRow++;
			}
			fclose(file);
			countSymbol = countSymbol - 1 - countRow;
			//printf("Test 1 => %d\n", countSymbol);
			//printf("Test 2 => %d\n", countRow);

			FILE* fileW;
			fopen_s(&fileW, array_output_files[i], "w");
			printf("File `%s` was successufuly created!\n", array_output_files[i]);

			fprintf(fileW, "%f\n", (double)countSymbol / countRow);
			fclose(fileW);

			//printf("Medium density in file %s => %f \n", array_files[i], (double)countSymbol / countRow);
		}

		return 0;
	}
	else {
		printf("There are no such options like : %s\n", option);
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
* fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) --- функція яка записує дані з масиву, на який вказує ptr, 
* у заданий файл stream.
*/
int task5(char option[]) {
	if (option[0] == '1') {
		char str[100] = "";
		printf("Input => ");
		fgets(str, 100, stdin);
		str[strlen(str) - 1] = '\0';

		//printf("Your input => %s", str);

		char* token = strtok(str, " ");
		char userInput2[100] = "";
		int userInput4;

		char** userFilename = (char**)malloc(1 * sizeof(char*));
		for (int i = 0; i < 1; i++)
			userFilename[i] = (char*)malloc(100 * sizeof(char));

		int count = 0;
		while (token != NULL) {
			count++;
			//printf("%s\n", token); 
			//char* ptr;
			//userInput = strtol(token, &ptr, 10);
			if (count == 1) {
				int test = 0;
				char compare1[100] = "-filename";
				for (int i = 0; compare1[i] != '\0'; i++) {
					if (token[i] != compare1[i])
						test = 1;
				}

				if (test != 0) {
					printf("Incorrect input!\nYour input should be like this: -filename name -rows rows\n");
					return -1;
				}
			}
			else if (count == 2) {
				userFilename[0] = token;
			}
			else if (count == 3) {
				int test = 0;
				char compare2[100] = "-rows";
				for (int i = 0; compare2[i] != '\0'; i++) {
					if (token[i] != compare2[i])
						test = 1;
				}

				if (test != 0) {
					printf("Incorrect input!\nYour input should be like this: -filename name -rows rows\n");
					return -1;
				}
			}
			else if (count == 4) {
				char* ptr;
				userInput4 = strtof(token, &ptr, 10);
			}
			else {
				printf("Incorrect number of arguments!\n");
				return -1;
			}
			token = strtok(NULL, " ");
		}

		if (count != 4) {
			printf("Incorrect number of arguments!\n");
			return -1;
		}

		//printf("Your input was: %s %d\n", userFilename[0], userInput4);
		FILE* file;
		fopen_s(&file, userFilename[0], "wb");

		if (file != NULL) {

			char* ptr;
			for (int i = 0; i < userInput4; i++) {
				fwrite(&i, sizeof(i), 1, file);
			}

			fclose(file);
		}
		
		return 0;
	}
	else if (option[0] == '2') {
		FILE* file;
		char buffer[255];

		// Opening file in reading mode
		fopen_s(&file, "task5_input_v1.txt", "r");
		char** userInputFILE = (char**)malloc(1 * sizeof(char*));
		for (int i = 0; i < 1; i++)
			userInputFILE[i] = (char*)malloc(50 * sizeof(char));

		int userInput = 0;
		int perhapsInput = NULL;
		int count1 = 0;;
		while (fgets(buffer, 255, file)) {
			//printf("%s", buffer);
			buffer[strlen(buffer) - 1] = '\0';
			userInputFILE[0] = buffer;
			count1++;
		}
		
		fclose(file);

		if (count1 != 1) {
			printf("Incorrect date in file\n");
			return -1;
		}
		else {
			//printf("Test -> %s\n", userInputFILE[0]);

			char* token = strtok(userInputFILE[0], " ");

			
			char** userInput2 = (char**)malloc(1 * sizeof(char*));
			for (int i = 0; i < 1; i++)
				userInput2[i] = (char*)malloc(50 * sizeof(char));
			
			int userInput4;
			int count = 0;
			while (token != NULL) {
				count++;
				//printf("%s\n", token);
				if (count == 1) {
					int test = 0;
					char compare1[100] = "-filename";
					for (int i = 0; compare1[i] != '\0'; i++) {
						if (token[i] != compare1[i])
							test = 1;
					}

					if (test != 0) {
						printf("Incorrect input!\nYour input should be like this: -filename name -rows rows\n");
						return -1;
					}
				}
				else if (count == 2) {
					userInput2[0] = token;
				}
				else if (count == 3) {
					int test = 0;
					char compare1[100] = "-rows";
					for (int i = 0; compare1[i] != '\0'; i++) {
						if (token[i] != compare1[i])
							test = 1;
					}

					if (test != 0) {
						printf("Incorrect input!\nYour input should be like this: -filename name -rows rows\n");
						return -1;
					}
				}
				else if (count == 4) {
					char* ptr;
					userInput4 = strtof(token, &ptr, 10);
				}
				token = strtok(NULL, " ");
			}
			if (count != 4) {
				printf("Incorrect date in file\n");
				return -1;
			}

			//printf("Date in file: %s %d\n", userInput2[0], userInput4);

			FILE* fileW;
			fopen_s(&fileW, userInput2[0], "wb");
			printf("File `%s` was successufuly created!\n", userInput2[0]);

			if (fileW != NULL) {

				char* ptr;
				for (int i = 0; i < userInput4; i++) {
					fwrite(&i, sizeof(i), 1, file);
				}

				fclose(fileW);
			}

			return 0;
		}

	}
	else {
		printf("There are no such options like : %s\n", option);
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
int task6(char option[]) {
	if (option[0] == '1') {
		char str[100] = "";
		printf("Input => ");
		fgets(str, 100, stdin);
		str[strlen(str) - 1] = '\0';

		//printf("Your input => %s", str);

		char* token = strtok(str, " ");
		//char userInput2[100] = "";
		int userInput4;
		int userInput6;

		char** userFilename = (char**)malloc(1 * sizeof(char*));
		for (int i = 0; i < 1; i++)
			userFilename[i] = (char*)malloc(100 * sizeof(char));

		int count = 0;
		while (token != NULL) {
			count++;
			//printf("%s\n", token); 
			//char* ptr;
			//userInput = strtol(token, &ptr, 10);
			if (count == 1) {
				int test = 0;
				char compare1[100] = "-filename";
				for (int i = 0; compare1[i] != '\0'; i++) {
					if (token[i] != compare1[i])
						test = 1;
				}

				if (test != 0) {
					printf("Incorrect input!\nYour input should be like this: -filename name -rows rows -cols cols\n");
					return -1;
				}
			}
			else if (count == 2) {
				userFilename[0] = token;
			}
			else if (count == 3) {
				int test = 0;
				char compare2[100] = "-rows";
				for (int i = 0; compare2[i] != '\0'; i++) {
					if (token[i] != compare2[i])
						test = 1;
				}

				if (test != 0) {
					printf("Incorrect input!\nYour input should be like this: -filename name -rows rows -cols cols\n");
					return -1;
				}
			}
			else if (count == 4) {
				char* ptr;
				userInput4 = strtol(token, &ptr, 10);
			}
			else if (count == 5) {
				int test = 0;
				char compare3[100] = "-cols";
				for (int i = 0; compare3[i] != '\0'; i++) {
					if (token[i] != compare3[i])
						test = 1;
				}

				if (test != 0) {
					printf("Incorrect input!\nYour input should be like this: -filename name -rows rows -cols cols\n");
					return -1;
				}
			}
			else if (count == 6) {
				char* ptr;
				userInput6 = strtol(token, &ptr, 10);
			}
			else {
				printf("Incorrect number of arguments!\n");
				return -1;
			}
			token = strtok(NULL, " ");
		}

		if (count != 6) {
			printf("Incorrect number of arguments!\n");
			return -1;
		}

		if (userInput4 == 0 || userInput6 == 0) {
			printf("Incorrect date!\n");
			return -1;
		}
		//printf("Your input was : %s %d %d\n", userFilename[0], userInput4, userInput6);

		FILE* fptr;
		errno_t err;

		err = fopen_s(&fptr, userFilename[0], "w");

		if (err != 0) {
			printf("file can't be created \n");
			return -1;
		}

		printf("File created successfully!\n");

		for (int i = 0; i < userInput4; i++) {
			for (int j = 0; j < userInput6; j++) {
				fprintf(fptr, "%d\t", 0);
			}
			fprintf(fptr, "\n");
		}
		fclose(fptr);

		return 0;
	}
	else if (option[0] == '2') {
	FILE* file;
	char buffer[255];

	// Opening file in reading mode
	fopen_s(&file, "task6_input_v1.txt", "r");
	char** userInputFILE = (char**)malloc(1 * sizeof(char*));
	for (int i = 0; i < 1; i++)
		userInputFILE[i] = (char*)malloc(50 * sizeof(char));

	int userInput = 0;
	int perhapsInput = NULL;
	int count1 = 0;;
	while (fgets(buffer, 255, file)) {
		//printf("%s", buffer);
		buffer[strlen(buffer) - 1] = '\0';
		userInputFILE[0] = buffer;
		count1++;
	}

	fclose(file);

	if (count1 != 1) {
		printf("Incorrect date in file\n");
		return -1;
	}
	else {
		//printf("Test -> %s\n", userInputFILE[0]);

		char* token = strtok(userInputFILE[0], " ");


		char** userInput2 = (char**)malloc(1 * sizeof(char*));
		for (int i = 0; i < 1; i++)
			userInput2[i] = (char*)malloc(50 * sizeof(char));

		int userInput4;
		int userInput6;
		int count = 0;
		while (token != NULL) {
			count++;
			//printf("%s\n", token);
			if (count == 1) {
				int test = 0;
				char compare1[100] = "-filename";
				for (int i = 0; compare1[i] != '\0'; i++) {
					if (token[i] != compare1[i])
						test = 1;
				}

				if (test != 0) {
					printf("Incorrect input!\nYour input should be like this: -filename name -rows rows\n");
					return -1;
				}
			}
			else if (count == 2) {
				userInput2[0] = token;
			}
			else if (count == 3) {
				int test = 0;
				char compare1[100] = "-rows";
				for (int i = 0; compare1[i] != '\0'; i++) {
					if (token[i] != compare1[i])
						test = 1;
				}

				if (test != 0) {
					printf("Incorrect input!\nYour input should be like this: -filename name -rows rows\n");
					return -1;
				}
			}
			else if (count == 4) {
				char* ptr;
				userInput4 = strtof(token, &ptr, 10);
			}

			else if (count == 5) {
				int test = 0;
				char compare1[100] = "-cols";
				for (int i = 0; compare1[i] != '\0'; i++) {
					if (token[i] != compare1[i])
						test = 1;
				}

				if (test != 0) {
					printf("Incorrect input!\nYour input should be like this: -filename name -rows rows\n");
					return -1;
				}
			}
			else if (count == 6) {
				char* ptr;
				userInput6 = strtof(token, &ptr, 10);
			}
			token = strtok(NULL, " ");
		}
		if (count != 6) {
			printf("Incorrect date in file\n");
			return -1;
		}

		//printf("Date in file: %s %d\n", userInput2[0], userInput4);

		FILE* fileW;
		fopen_s(&fileW, userInput2[0], "wb");
		printf("File `%s` was successufuly created!\n", userInput2[0]);

		if (fileW != NULL) {

			for (int i = 0; i < userInput4; i++) {
				for (int j = 0; j < userInput6; j++) {
					fprintf(fileW, "%d\t", 0);
				}
				fprintf(fileW, "\n");
			}
			fclose(fileW);
		}

		return 0;
	}
	}
	else {
		printf("There are no such options like : %s\n", option);
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
int task7(char option[]) {
	if (option[0] == '1') {
		char str[100] = "";
		printf("Input => ");
		fgets(str, 100, stdin);
		str[strlen(str) - 1] = '\0';

		//printf("Your input => %s", str);

		char* token = strtok(str, " ");
		int userInput4;
		int userInput6PH = NULL;

		char** userFilename = (char**)malloc(2 * sizeof(char*));
		for (int i = 0; i < 1; i++)
			userFilename[i] = (char*)malloc(100 * sizeof(char));

		int count = 0;
		while (token != NULL) {
			count++;
			//printf("%s\n", token); 
			if (count == 1) {
				int test = 0;
				char compare1[100] = "-filename1";
				for (int i = 0; compare1[i] != '\0'; i++) {
					if (token[i] != compare1[i])
						test = 1;
				}

				if (test != 0) {
					printf("Incorrect input!\nYour input should be like this: -filename1 name1 -filename2 name2 -rows rows\n");
					return -1;
				}
			}
			else if (count == 2) {
				userFilename[0] = token;
			}
			else if (count == 3) {
				int test = 0;
				char compare2[100] = "-filename2";
				for (int i = 0; compare2[i] != '\0'; i++) {
					if (token[i] != compare2[i])
						test = 1;
				}

				if (test != 0) {
					printf("Incorrect input!\nYour input should be like this: -filename1 name1 -filename2 name2 -rows rows\n");
					return -1;
				}
			}
			else if (count == 4) {
				userFilename[1] = token;
			}
			else if (count == 5) {
				int test = 0;
				char compare3[100] = "-rows";
				for (int i = 0; compare3[i] != '\0'; i++) {
					if (token[i] != compare3[i])
						test = 1;
				}

				if (test != 0) {
					printf("Incorrect input!\nYour input should be like this: -filename1 name1 -filename2 name2 -rows rows\n");
					return -1;
				}
			}
			else if (count == 6) {
				char* ptr;
				userInput6PH = strtol(token, &ptr, 10);
			}
			else {
				printf("Incorrect number of arguments!\n");
				return -1;
			}
			token = strtok(NULL, " ");
		}

		//printf("Your input was %s %s %d\n", userFilename[0], userFilename[1], userInput6PH);

		if (userInput6PH == NULL) {
			FILE* file;
			errno_t err;
			char ch;
			err = fopen_s(&file, userFilename[0], "r");

			if (err != 0) {
				printf("file can't be opened \n");
				return -1;
			}

			int count1 = 0;
			while (!feof(file)) {
				ch = fgetc(file);
				//printf("%c", ch);
				if (ch == '\n') count1++;
			}
			fclose(file);

			FILE* file1;
			errno_t err1;
			char ch1;
			err1 = fopen_s(&file1, userFilename[1], "r");

			if (err1 != 0) {
				printf("file can't be opened \n");
				return -1;
			}

			int count2 = 0;
			while (!feof(file1)) {
				ch1 = fgetc(file1);
				//printf("%c", ch);
				if (ch1 == '\n') count2++;
			}
			fclose(file1);

			//printf("Test -> %d %d\n", count1, count2);
			userInput6PH = (count1 > count2) ? count1 : count2;
			//printf("Test -> %d\n", userInput6PH);


			FILE* file11;
			errno_t err11;
			char ch11;

			FILE* file2;
			errno_t err2;
			char ch2;

			// Opening file in reading mode
			err11 = fopen_s(&file11, userFilename[0], "r");
			err2 = fopen_s(&file2, userFilename[1], "r");

			int count = 0;
			char* ptr1;
			

			if ((err11 != 0) && (err2 != 0)) {
				printf("files can't be opened \n");
				return -1;
			}

			while ((!feof(file11) || !feof(file2)) && count != userInput6PH) {
				ch11 = fgetc(file11);
				ch2 = fgetc(file2);
				//printf("compare 1 => %c 2 => %c", ch1, ch2);
				if (ch11 != ch2) {
					printf("Not equal files\n");
					return -1;
				}

				if (ch11 == '\n') count++;
			}

			printf("The content in the files is the same");

			fclose(file11);
			fclose(file2);

			return 0;
		}
		else {
			FILE* file11;
			errno_t err11;
			char ch11;

			FILE* file2;
			errno_t err2;
			char ch2;

			// Opening file in reading mode
			err11 = fopen_s(&file11, userFilename[0], "r");
			err2 = fopen_s(&file2, userFilename[1], "r");

			int count = 0;
			char* ptr1;


			if ((err11 != 0) && (err2 != 0)) {
				printf("files can't be opened \n");
				return -1;
			}

			while ((!feof(file11) || !feof(file2)) && count != userInput6PH) {
				ch11 = fgetc(file11);
				ch2 = fgetc(file2);
				//printf("compare 1 => %c 2 => %c", ch1, ch2);
				if (ch11 != ch2) {
					printf("Not equal files\n");
					return -1;
				}

				if (ch11 == '\n') count++;
			}

			//ph
			printf("The content in the files is the same");

			fclose(file11);
			fclose(file2);
			return 0;
		}	
	}
	else if (option[0] == '2') {
		FILE* file1;
		char buffer1[255];

		char** userFilename = (char**)malloc(2 * sizeof(char*));
		for (int i = 0; i < 1; i++)
			userFilename[i] = (char*)malloc(100 * sizeof(char));
		
		fopen_s(&file1, "task7_input_v3.txt", "r");
		int count = 0;

		int userInput6PH = NULL;

		while (fgets(buffer1, 255, file1)) {
			count++;
			buffer1[strlen(buffer1) - 1] = '\0';
			//printf("Test 1 -> %s\n", buffer1);
			char* token = strtok(buffer1, " ");
			int count1 = 0;
			while (token != NULL) {
				count1++;

				//printf("%s\n", token); 
				if (count1 == 1) {
					
					int test = 0;
					char compare1[100] = "-filename1";
					for (int i = 0; compare1[i] != '\0'; i++) {
						if (token[i] != compare1[i])
							test = 1;
					}
					
					if (test != 0) {
						printf("Incorrect input!\nYour input should be like this: -filename1 name1 -filename2 name2 -rows rows\n");
						return -1;
					}
				}
				else if (count1 == 2) {
					userFilename[0] = token;
				}
				else if (count1 == 3) {
					int test = 0;
					char compare2[100] = "-filename2";
					for (int i = 0; compare2[i] != '\0'; i++) {
						if (token[i] != compare2[i])
							test = 1;
					}
					
					if (test != 0) {
						printf("Incorrect input!\nYour input should be like this: -filename1 name1 -filename2 name2 -rows rows\n");
						return -1;
					}
				}
				else if (count1 == 4) {
					userFilename[1] = token;
				}
				else if (count1 == 5) {
					int test = 0;
					char compare3[100] = "-rows";
					for (int i = 0; compare3[i] != '\0'; i++) {
						if (token[i] != compare3[i])
							test = 1;
					}
					
					if (test != 0) {
						printf("Incorrect input!\nYour input should be like this: -filename1 name1 -filename2 name2 -rows rows\n");
						return -1;
					}
				}
				else if (count1 == 6) {
					char* ptr;
					userInput6PH = strtol(token, &ptr, 10);
				}
				else {
					printf("Incorrect number of arguments!\n");
					return -1;
				}


				token = strtok(NULL, " ");
			}

			if (count >= 2) {
				printf("Incorrect date in file\n");
				return -1;
			}
		}

		fclose(file1);
		
		//printf("Date in file : %s %s %d\n", userFilename[0], userFilename[1], userInput6PH);
		if (userInput6PH == NULL) {
			FILE* file;
			errno_t err;
			char ch;
			err = fopen_s(&file, userFilename[0], "r");

			if (err != 0) {
				printf("file can't be opened \n");
				return -1;
			}

			int count1 = 0;
			while (!feof(file)) {
				ch = fgetc(file);
				//printf("%c", ch);
				if (ch == '\n') count1++;
			}
			fclose(file);

			FILE* file1;
			errno_t err1;
			char ch1;
			err1 = fopen_s(&file1, userFilename[1], "r");

			if (err1 != 0) {
				printf("file can't be opened \n");
				return -1;
			}

			int count2 = 0;
			while (!feof(file1)) {
				ch1 = fgetc(file1);
				//printf("%c", ch);
				if (ch1 == '\n') count2++;
			}
			fclose(file1);

			//printf("Test -> %d %d\n", count1, count2);
			userInput6PH = (count1 > count2) ? count1 : count2;
			//printf("Test -> %d\n", userInput6PH);


			FILE* file11;
			errno_t err11;
			char ch11;

			FILE* file2;
			errno_t err2;
			char ch2;

			// Opening file in reading mode
			err11 = fopen_s(&file11, userFilename[0], "r");
			err2 = fopen_s(&file2, userFilename[1], "r");

			int count = 0;
			char* ptr1;


			if ((err11 != 0) && (err2 != 0)) {
				printf("files can't be opened \n");
				return -1;
			}
			FILE* fp;
			fopen_s(&fp, "task7_output_v1.txt", "w");
			printf("File `task7_output_v1.txt` was successufuly created!\n");

			while ((!feof(file11) || !feof(file2)) && count != userInput6PH) {
				ch11 = fgetc(file11);
				ch2 = fgetc(file2);
				//printf("compare 1 => %c 2 => %c", ch1, ch2);
				if (ch11 != ch2) {
					fprintf(fp, "Not equal files\n");
					//printf("Not equal files\n");
					return -1;
				}

				if (ch11 == '\n') count++;
			}

			
			if (fp == NULL)
			{
				printf("Error opening the file task7_output_v1.txt");
				return -1;
			}
			// write to the text file
			fprintf(fp, "The content in the files is the same\n");

			// close the file
			fclose(fp);

			fclose(file11);
			fclose(file2);

			return 0;
		}
		else {
			FILE* file11;
			errno_t err11;
			char ch11;

			FILE* file2;
			errno_t err2;
			char ch2;

			// Opening file in reading mode
			err11 = fopen_s(&file11, userFilename[0], "r");
			err2 = fopen_s(&file2, userFilename[1], "r");

			int count = 0;
			char* ptr1;


			if ((err11 != 0) && (err2 != 0)) {
				printf("files can't be opened \n");
				return -1;
			}
			FILE* fp;
			fopen_s(&fp, "task7_output_v1.txt", "w");
			printf("File `task7_output_v1.txt` was successufuly created!\n");

			while ((!feof(file11) || !feof(file2)) && count != userInput6PH) {
				ch11 = fgetc(file11);
				ch2 = fgetc(file2);
				//printf("compare 1 => %c 2 => %c", ch1, ch2);
				if (ch11 != ch2) {
					fprintf(fp, "Not equal files\n");
					//printf("Not equal files\n");
					return -1;
				}

				if (ch11 == '\n') count++;
			}

			
			if (fp == NULL)
			{
				printf("Error opening the file task7_output_v1.txt\n");
				return -1;
			}
			// write to the text file
			fprintf(fp, "The content in the files is the same\n");

			// close the file
			fclose(fp);

			fclose(file11);
			fclose(file2);
			return 0;
		}
		
		return 0;
	}
	else {
		printf("There are no such options like : %s\n", option);
		return -1;
	}
}
