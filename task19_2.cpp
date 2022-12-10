#include <iostream>
#include <vector>

int main3() {
	int d, n;

	std::cout << "Input number of vectors => ";
	std::cin >> n;

	std::cout << "Input dimension of single vector => ";
	std::cin >> d;

	std::vector<std::vector<int>> arr;

	for (int i = 0; i < n; i++) {
		std::vector<int> vec;
		for (int j = 0; j < d; j++) {
			int num;

			std::cout << "input num =>";
			std::cin >> num;
			vec.push_back(num);
		}
	}

	float sum = 0;

	for (int i = 0; i < n; i++) {
		float sum1 = 0;
		for (int j = 0; j < d; j++) {
			sum += arr[i][j] * arr[i][j];
		}

		sum += sqrt(sum1);
	}

	std::cout << "Res => " << sum;

	return 0;
}
