#include <iostream>

typedef struct {
	int r;
	int x;
	int y;
} Subject;

Subject input_circle() {
	Subject example_circle = { NULL, NULL, NULL };

	std::cout << "Input circle(radius, x coordinate, y coordinate): ";
	std::cin >> example_circle.r >> example_circle.x >> example_circle.y;

	return example_circle;
}

void output_circle(Subject user_circle) {
	std::cout << "Your circle => (" << user_circle.x << "," << user_circle.y << ") with radius: " 
		<< user_circle.r << "\n";
}

int main8() {
	Subject c;
	c = input_circle();
	output_circle(c);

	return 0;
}