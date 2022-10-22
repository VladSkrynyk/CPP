#include <stdio.h>
#include <stdint.h>
#include <math.h>

void task26() {
	int num1, num2, i, bitStatus1, bitStatus2;
	bool check = false;
	printf("num1,num2 enter:");
	scanf_s("%d %d", &num1, &num2);
	for (i = 7; i != -1; i--)
	{
		bitStatus1 = (num1 >> i) & 1;
		bitStatus2 = (num2 >> i) & 1;
		printf("The %d bit is set to %d\n", i, bitStatus1);
		printf("The %d bit is set to %d\n", i, bitStatus2);
		if (bitStatus1 == bitStatus2 && bitStatus1 == 0)
		{
			check = true;
		}

	}
	if (check)
	{
		printf("there are equal bits in same positions");
	}

	else
	{
		printf("there are not equal bits in same positions");
	}
}

int main() {
	task26();
}