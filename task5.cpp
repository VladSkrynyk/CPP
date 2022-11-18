#include <iostream>
#include <cstdlib>
#include <string>
#define N 5


typedef struct {
	int hight;
	std::string name;
} Mountain;

Mountain input_mountain() {
	Mountain example = { NULL, " "};

	std::cout << "Input mountain hight: ";
	std::cin >> example.hight;

	std::cout << "Input mountain name: ";
	std::cin >> example.name;

	return example;
}

void output_mountain(Mountain user) {
	std::cout << "Your mountain => (" << user.hight << "," << user.name << ")\n";
}

Mountain find_by_hight(Mountain arr[]) {
	int max = arr[0].hight;
	for (int i = 0; i < N; i++) {
		if (arr[i].hight > max) max = arr[i].hight;
	}

	for (int i = 0; i < N; i++) {
		if (arr[i].hight == max) return arr[i];
	}

}

Mountain find_by_name(Mountain arr[], std::string name) {
	for (int i = 0; i < N; i++) {
		if (arr[i].name == name) return arr[i];
	}

	std::cout << "No such mountain with name => " << name;
}

int main7() {

	Mountain mountains_array[N];

	for (int i = 0; i < N; i++) {
		mountains_array[i] = input_mountain();
		output_mountain(mountains_array[i]);
	}

	std::string name;
	std::cout << "Input name => ";
	std::cin >> name;

	Mountain f1 = find_by_name(mountains_array, name);
	std::cout << "Mountain with name " << name << " has hight =>" << f1.hight << "\n";

	Mountain f2 = find_by_hight(mountains_array);
	std::cout << "Mountain with name " << name << " is the hightest =>" << f2.hight << "\n";

	return 0;
}