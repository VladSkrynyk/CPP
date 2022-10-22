#include <stdio.h>
#include <stdint.h>
#include <math.h>

void task6_1() {
	unsigned char n;

	printf("Input: ");
	scanf_s("%hhu", &n);

	long long unsigned m = 1UL << n;//uint64_t

	printf("Res: %llu", m);
}

int main() {
	task6_1();
}