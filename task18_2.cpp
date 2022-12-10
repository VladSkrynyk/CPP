#include <iostream>

template <typename T>
class MyStack {
public:
	int length = 0;
	T* myArray = (T*)malloc(length * sizeof(T));

	void push_back(T num) {
		this->length++;
		free(this->myArray);

		this->myArray = (T*)malloc(this->length * sizeof(T));
		this->myArray[this->length - 1] = num;
	}

	void print() {
		std::cout << "Length => " << sizeof(myArray) * this->length / sizeof(int) << "\n";
	}
};

template <typename T>
int fillArray(MyStack<T> arr) {
	int userInput;
	std::cout << "Input num => ";
	std::cin >> userInput;

	while (userInput != 0) {

		arr.push_back(userInput);

		int userInput;
		std::cout << "Input num => ";
		std::cin >> userInput;
	}

	return arr.length;
}

int main2() {
	MyStack<int> arr;
	fillArray(arr);

	return 0;
}