#include <stdio.h>
#include <stdint.h>
#include <math.h>

void task6_4() {
	uint32_t n;

	printf("n=");
	int r = scanf_s("%u", &n);

	if (r != 1) {
		printf("cannot input");
		return;
	}

	printf("%x", n);

	uint32_t first8bit = n & 0xFF;//8xFF
	uint32_t last8bit = n >> 24;

	uint32_t m = ((n << 8) >> 16) << 8;
	m |= (first8bit << 24);
	m |= last8bit;

	printf("%u", m);
}

int main() {
	task6_4();
}