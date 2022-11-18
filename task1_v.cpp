#include <stdio.h>

typedef struct Point {
	int x;
	int y;
};

typedef struct Rectangle {
	Point first;
	Point second;
};

void input_Date(Rectangle* user_Date) {
	printf("Input first point (x y): ");
	scanf_s("%d", &user_Date->first.x);
	scanf_s("%d", &user_Date->first.y);

	printf("Input second point (x y): ");
	scanf_s("%d", &user_Date->second.x);
	scanf_s("%d", &user_Date->second.y);
}

void show_Date(Rectangle* user_Date) {
	printf("Your rectangle => (%d %d) (%d %d)", user_Date->first.x, user_Date->first.y, 
		user_Date->second.x, user_Date->second.y);
}

int main4() {

	struct Rectangle user_Date;
	input_Date(&user_Date);
	show_Date(&user_Date);

	return 0;
}