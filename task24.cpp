#include <stdio.h>
#include <stdint.h>
#include <math.h>

int GetMsbPos(unsigned int num)
{
	int cnt = 0;

	while (num) {
		cnt++;
		num = num >> 1;
	}

	return cnt - 1;
}

int GetLsbPos(unsigned int num)
{
	int number = 0, i = 0, bigNum = 0, bitStatus, res = 0;

	while (bigNum <= num) {
		bitStatus = (num >> i) & 1;
		bigNum += pow(2, i);

		if (bitStatus == 1) {
			res = i;
			break;
		}

		i++;
	}

	return res;
}


int main() {
	/*unsigned int num = 0;
	int pos1 = 0;
	int pos2 = 0;

	printf("Enter Number: ");
	scanf_s("%d", &num);

	pos1 = GetMsbPos(num);
	pos2 = GetLsbPos(num);
	printf("Position of MSB bit is: %d\nPosition of LSB bit is: %d", pos1, pos2);*/
}