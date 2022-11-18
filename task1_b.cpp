#include <stdio.h>

typedef struct Chess {
	char letter;
	int number;
};

int input_Date(Chess* user_Date) {
	printf("Input (a 5): ");
	scanf_s("%c",&user_Date->letter);
	scanf_s("%d", &user_Date->number);
	
	if (user_Date->number >= 1 && user_Date->number <= 8) {
		return 0;
	}
	else return -1;
}

void show_Date(Chess* user_Date) {
	printf("Your date => %c %d", user_Date->letter, user_Date->number);
}

int main2() {

	struct Chess user_Date = { '0', 0};
	if (input_Date(&user_Date) == -1) {
		printf("Incorrect input!");
		return -1;
	}
	show_Date(&user_Date);

	return 0;
}