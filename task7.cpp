#include <stdio.h>
#include <stdint.h>
#include <math.h>

void task6_7() {
	uint32_t A = 0x01020384;

	uint32_t A0 = A & 0x2F;
	uint32_t A3 = A >> 24;

	if (A0 == 0x04 && A3 == 0x01) {
		printf(" little endien");
	}
	if (A0 == 0x01 && A3 == 0x04) {
		printf(" big endien");
	}
}

int main() {
	/*task6_7();*/
	/*uint32_t m = 2;
	printf("pravui: %llu", m & 1);*/
}