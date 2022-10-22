#include <stdio.h>
#include <stdint.h>
#include <math.h>

void task6_2() {
	int n;
	unsigned m;
	printf("n,m=");
	scanf_s("%d,%u", &n, &m);

	int res = n | (1 << m);

	printf("r=%d", res);
}

int main() {
	task6_2();
}