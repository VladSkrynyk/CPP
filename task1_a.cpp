#include <stdio.h>

typedef struct Date {
	int number;
	int month;
	int year;
};

int input_Date(Date* user_Date) {
	printf("Input your data(day/month/year): ");
	scanf_s("%d/%d/%d", &user_Date->number, &user_Date->month, &user_Date->year);
	if (user_Date->number <= 0 || user_Date->number >= 32) return -1;
	else if (user_Date->month <= 0 || user_Date->month >= 12) return -1;
	else return 0;
}

void show_Date(Date* user_Date) {
	printf("Your date => %d/%d/%d", user_Date->number, user_Date->month, user_Date->year);
}

int main1() {

	struct Date user_Date = {NULL, NULL, NULL};
	if (input_Date(&user_Date) == -1) {
		printf("Incorrect input!");
		return -1;
	}
	show_Date(&user_Date);

	return 0;
}