#include <stdio.h>
#include <stdint.h>
#include <math.h>

void task6_3() {
	uint64_t m;
	uint8_t j;

	printf("m=");
	scanf_s("%llu", &m);//SCNu64

	printf("j=");
	scanf_s("%hhu", &j);

	m = m & ~(1 << j);

	printf("m=%llu", m);//PRIu64

}

int main() {
	task6_3();
}