#include <iostream>
#include <string>

using namespace std;

typedef struct {
	int number_of_name;
	char femaleOrmale;
	int height;
} Pi;

typedef struct {
	string name;
} Li;

Pi input_p(int number) {
	Pi example_p = { number, NULL, NULL };

	std::cout << "Input person date(m for male and f for female, height): ";
	std::cin >> example_p.femaleOrmale >> example_p.height;

	return example_p;
}

void output_p(Pi user_p) {
	std::cout << "Person is => (" << user_p.number_of_name << "," << user_p.femaleOrmale << ") with height: "
		<< user_p.height << "\n";
}

Li input_l() {
	Li example_p = { "" };

	std::cout << "Input person name: ";
	std::cin >> example_p.name;

	return example_p;
}

void output_l(Li user_p) {
	std::cout << "Person name is => (" << user_p.name << ")\n";
}


int main1() {

	Pi array_persons[4];
	Li array_names[4];

	for (int i = 0; i < 4; i++) {
		array_persons[i] = input_p(i);
		output_p(array_persons[i]);

		array_names[i] = input_l();
		output_l(array_names[i]);
	}

	int average_height_of_women = 0;
	int count = 0;
	string the_logest;
	int max_height = -10;
	for (int i = 0; i < 4; i++) {
		if (array_persons[i].femaleOrmale == 'f') {
			count++;
			average_height_of_women += array_persons[i].height;
		}

		if (array_persons[i].femaleOrmale == 'm') {
			if (array_persons[i].height > max_height) {
				max_height = array_persons[i].height;
				the_logest = array_names[i].name;
			}
		}
	}

	cout << "Average height of women is: " << (float)average_height_of_women / count << "\n";
	cout << "Name of heighest men is: " << the_logest;

	return 0;
}
