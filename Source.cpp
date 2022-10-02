#include<stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h> 


// Laba3 3.1-3.7  3.18  3.23-d)

uint16_t mult(uint8_t x, uint8_t y) {
	return (uint16_t)((uint32_t)x * y);
}

void print_digits(unsigned n) {
	unsigned a = n % 10;
	unsigned b = (n / 10) % 10;
	unsigned c = n / 100;

	printf("%u %u %u\n", a, b, c);
}

unsigned sum_digit(unsigned n) {
	unsigned a = n % 10;
	unsigned b = (n / 10) % 10;
	unsigned c = n / 100;

	return a + b + c;
}

unsigned inverse(unsigned n) {
	unsigned a = n % 10;
	unsigned b = (n / 10) % 10;
	unsigned c = n / 100;

	return a * 100 + b * 10 + c;
}

bool perestanovky(unsigned n) {
	unsigned a = n % 10;
	unsigned b = (n / 10) % 10;
	unsigned c = n / 100;

	if (a == b || a == c || b == c) return false;

	printf("%u\n", 100 * a + 10 * b + c);
	printf("%u\n", 100 * a + 10 * c + b);
	printf("%u\n", 100 * b + 10 * a + c);
	printf("%u\n", 100 * b + 10 * c + a);
	printf("%u\n", 100 * c + 10 * b + a);
	printf("%u\n", 100 * c + 10 * a + b);

	return true;
}

int sqr_eqn_solve(double a, double b, double c) {
	double D = b * b - 4 * a * c;
	double x1, x2;

	if (fabs(a) < 0.000001) {
		if (fabs(b) < 0.0000001) {
			if (fabs(c) < 0.0000001) {
				printf("INFINITY");
				return -1;
			}
			printf("Not equation");
			return 0;
		}
		printf("One linear root");
		x1 = -c / b;
		printf("x1 = %lf\n", x1);
		return 1;
	}

	if (D < 0) {
		printf("No roots\n");
		return 0;
	}
	else if (fabs(D)<0.000000001) {
		printf("One root");
		x1 = -b / 2 / a;
		printf(" x1 = %lf", x1);
		return 1;
	}
	else {
		printf("Two root ");
		x1 = (-b - sqrt(D)) / 2 / a;
		x2 = (-b + sqrt(D)) / (2 * a);
		printf("x1 = %lf, x2 = %lf", x1, x2);
	}
	return 2;
}

int sqr_eqn_solve2(double a, double b, double c) {
	double D = b * b - 4 * a * c;
	double x1, x2, x3, x4;

	if (fabs(a) < 0.000001) {
		if (fabs(b) < 0.0000001) {
			if (fabs(c) < 0.0000001) {
				printf("INFINITY");
				return -1;
			}
			printf("Not equation");
			return 0;
		}
		
		x1 = -c / b;
		if (x1 < 0) {
			printf("Not equation");
			return 0;
		}
		else {
			printf("Two linear root\n");
			printf("x1 = %lf\nx2 = %lf", sqrt(x1), -1 * sqrt(x1));
			return 2;
		}
	}

	if (D < 0) {
		printf("No roots\n");
		return 0;
	}
	else if (fabs(D) < 0.000000001) {
		x1 = -b / 2 / a;
		if (x1 > 0) {
			printf("Two roots");
			printf(" x1 = %lf\nx2 = %lf", sqrt(x1), -1 * sqrt(x1));
			return 2;
		}
		else {
			printf("No roots");
			return -1;
		}
		
	}
	else {
		printf("Four root ");
		x1 = (-b - sqrt(D)) / 2 / a;
		x2 = (-b + sqrt(D)) / (2 * a);
		printf("x1 = %lf, x2 = %lf, x3 = %lf, x4 = %lf", sqrt(x1), -1 * sqrt(x1), sqrt(x2), -1 * sqrt(x2));
	}
	return 2;
}


void swap(char* x, char* y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permute(char* a, int i, int n)
{
	int j;
	if (i == n)
		printf("%s\n", a);
	else {
		for (j = i; j <= n; j++)
		{
			swap((a + i), (a + j));
			permute(a, i + 1, n);
			swap((a + i), (a + j));
		}
	}
}

double isReLu(double tl, double tr, double al, double ar, double x) {
	if (x <= tl) {
		return tl + al * (x - tl);
	}
	else if (x > tl && x < tr) {
		return 0;
	}
	else {
		return tr + ar * (x - tr);
	}
}

double derivative_isReLu(double tl,double tr,double al,double ar,double x) {
	if (x <= tl) {
		return -1;
	}
	else if (x > tl && x < tr) {
		return 0;
	}
	else {
		return -1;
	}
}

int main() {
	//3.1
	/*unsigned n;
	printf("n=");
	scanf_s("%u", &n);

	if (n >= 1000 || n < 100) {
		printf("The number %u is not 3-digit!!!", &n);
		return 0;
	}

	print_digits(n);
	printf("sum of digit is: %u\n", sum_digit(n));
	printf("inverse: %u\n", inverse(n));*/

	//3.2
	/*unsigned n;
	printf("n=");
	scanf_s("%u", &n);
	if (!perestanovky(n)) {
		printf("there are similar digits!");
	}*/

	//alternative
	/*char a[5] = { '1', '2', '3' };
	int n;
	n = strlen(a);
	printf("Permutaions:\n");
	permute(a, 0, n - 1);*/

	//3.3
	//int a, b, c;
	//unsigned long long res;
	//printf("Input a, b, c: ");
	//int r_s = scanf_s("%d,%d,%d", &a, &b, &c);
	//if (r_s != 3) {
	//	printf("incorrect input");
	//	return - 1;
	//}

	//res = (unsigned long long) a * b * c; // 2^30 < 2^31

	//printf("R=%llu", res);

	//if (abs(a) < pow(2, 21) && abs(b) < pow(2, 21) && abs(c) < pow(2, 21)) {
	//	printf("R=%llu\n", res);
	//}
	
	//3.4
	/*unsigned char a, b;
	unsigned short c;

	printf("Input 8-bit integers a,b:\n");
	int r_s = scanf_s("%hhu %hhu", &a, &b);
	if (r_s != 2) {
		printf("Incorrect input!");
		return - 1;
	}

	c = mult(a, b);
	printf("c=%hu", c);*/

	//3.5
	/*int a, b;
	printf("Input two variables: ");
	scanf_s("%d %d", &a, &b);

	if (a > b) {
		printf("First number is bigger than second!\n");
		printf("Max is: %d\n", a);
		printf("Min is: %d\n", b);
	}
	else if (b > a) {
		printf("Second number is bigger than first!\n");
		printf("Max is: %d\n", b);
		printf("Min is: %d\n", a);
	}
	else {
		printf("Two number is equal to each other!\n");
	}*/

	//3.6
	/*double a, b, c;

	printf("Include a,b,c: ");
	scanf_s("%lf %lf %lf", &a, &b, &c);
	a = fabs(a);
	b = fabs(b);
	c = fabs(c);

	if (a == b && b == c) {
		printf("All numbers are equal");
		return 0;
	}
	else if (a == b) {
		if (a > c)
			printf("Max is: %lf\nMin is: %lf", a, c);
		else
			printf("Max is: %lf\nMin is: %lf", c, b);
	}
	else if (a == c) {
		if (a > b)
			printf("Max is: %lf\nMin is: %lf", a, b);
		else
			printf("Max is: %lf\nMin is: %lf", b, a);
	}
	else if (b == c) {
		if (b > a)
			printf("Max is: %lf\nMin is: %lf", b, a);
		else
			printf("Max is: %lf\nMin is: %lf", a, b);
	}
	else {

		if (a > b) {
			if (a > c) {
				printf("Max is: %lf\n", a);
				if (b > c) {
					printf("Min is: %lf\n", c);
				}
				else {
					printf("Min is: %lf\n", b);
				}
			}
			else if (b > c) {
				printf("Min is: %lf\n", c);
			}
			else {
				printf("Min is: %lf\n", b);
			}

		}
		else if (a > c) {
			if (a > b) {
				printf("Max is: %lf\n", a);
				printf("Min is: %lf\n", c);
			}
			else if (b > a) {
				printf("Max is: %lf\n", b);
				printf("Min is: %lf\n", c);
			}
			else if (b > c) {
				printf("Min is: %lf\n", c);
			}
			else {
				printf("Min is: %lf\n", a);
			}
		}
		else {
			printf("Min is: %lf\n", a);
			if (b > c) {
				printf("Max is: %lf\n", b);
			}
			else {
				printf("Max is: %lf\n", c);
			}
		}
		return 0;
	}*/

	//3.7
	/*double a, b, c;

	printf("Input: ");
	scanf_s("%lf %lf %lf", &a, &b, &c);

	sqr_eqn_solve(a, b, c);
	sqr_eqn_solve2(a, b, c);*/
	
	//3.18
	/*double x1l, y1l, x1r, y1r, x2l, y2l, x2r, y2r, xminl, yminl, xminr, yminr;

	printf("1 => Input the coordinates of the lower left vertex(x,y): ");
	scanf_s("%lf,%lf", &x1l, &y1l);

	printf("1 => Input the coordinates of the upper right vertex(x,y): ");
	scanf_s("%lf,%lf", &x1r, &y1r);

	printf("2 => Input the coordinates of the lower left vertex(x,y): ");
	scanf_s("%lf,%lf", &x2l, &y2l);

	printf("2 => Input the coordinates of the upper right vertex(x,y): ");
	scanf_s("%lf,%lf", &x2r, &y2r);

	if (x1l < x2l) {
		xminl = x1l;
	}
	else if (x1l > x2l) {
		xminl = x2l;
	}
	else {
		xminl = x1l;
	}

	if (y1l < y2l) {
		yminl = y1l;
	}
	else if (y1l > y2l) {
		yminl = y2l;
	}
	else {
		yminl = y1l;
	}

	if (x1r < x2r) {
		xminr = x2r;
	}
	else if (x1r > x2r) {
		xminr = x1r;
	}
	else {
		xminr = x1r;
	}

	if (y1r < y2r) {
		yminr = y2r;
	}
	else if (y1r > y2r) {
		yminr = y1r;
	}
	else {
		yminr = y1r;
	}

	printf("Lower left vertex(x,y): (%lf, %lf)\nUpper right vertex(x,y): (%lf, %lf)", xminl, yminl, xminr, yminr);*/
	
	//3.23-d)
	/*double tl, tr, al, ar, x;
	printf("Input parametrs(tl,tr,al,ar,x): ");
	scanf_s("%lf,%lf,%lf,%lf,%lf", &tl, &tr, &al, &ar, &x);

	printf("Function: %lf\n", isReLu(tl, tr, al, ar, x));
	if (derivative_isReLu(tl, tr, al, ar, x) == -1) {
		printf("Derivative not exiest");
	}
	else {
		printf("Derivative: %lf", derivative_isReLu(tl, tr, al, ar, x));
	}*/
	
	

}