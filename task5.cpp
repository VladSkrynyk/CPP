#include <stdio.h>
#include <stdint.h>
#include <math.h>

void task6_5() {
	int n = 127;
	int max1 = 1, tempmax = 1;
	for (int i = 0; i < sizeof(n) * 8; i++) {
		int bit = (n >> i) % 1;
		int next_bit = (n >> i + 1) % 1;
		if (bit == next_bit && bit == 1) {
			tempmax += 1;
			if (tempmax > max1) {
				max1 = tempmax;
			}
		}
		else {
			tempmax = 1;
		}
	}
	printf("%d", max1);
}

int main() {
	task6_5();
}