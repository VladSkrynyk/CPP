#include <stdio.h>
#include <math.h>
// Laba1 1.1-1.9   1.18    1.21 1.20

int multiple2operation(int x) {
	int x2 = x * x;
	return x2 * x2;
}

int multiple3operation(int x) {
	int x2 = x * x;
	int x4 = x2 * x2;
	return x4 * x2;
}

int multiple4operation(int x) {
	int x2 = x * x;
	int x4 = x2 * x2;
	int x8 = x4 * x4;
	return x8 * x;
}

int multiple5operation(int x) {
	int x2 = x * x;
	int x3 = x2 * x;
	int x6 = x3 * x3;
	int x12 = x6 * x6;
	return x12 * x3;
}

int multiple6operation(int x) {
	int x2 = x * x;
	int x4 = x2 * x2;
	int x8 = x4 * x4;
	int x16 = x8 * x8;
	int x24 = x16 * x8;
	return x24 * x4;
}

int secondMultiple6operation(int x) {
	int x2 = x * x;
	int x4 = x2 * x2;
	int x8 = x4 * x4;
	int x16 = x8 * x8;
	int x32 = x16 * x16;
	return x32;
}


int main() {
	// Task1
	 
	/*printf("1) - %d\n", 2 + 31);
	printf("2) - %d\n", 45 * 54 - 11);
	printf("3) - %d\n", (int)15 / 4);
	printf("4) - %.2f\n", (float)15.0 / 4);
	printf("5) - %d\n", 67 % 5);
	printf("6) - %.1f\n", (2 * 45.1 + 3.2) / 2);*/
	
	//Task 2
	 
	/*float x1 = 0.00001f;
	double x2 = 1e-4;
	long double x3 = pow(10, -4); 
	double y1 = 24.33e5;
	double s5 = sqrt(5);
	double l2 = log(100);
	printf("%.4f %.4lf %.4Lf %.4f %.4f %.4f", x1, x2, x3, y1, s5, l2);*/

	//Task 3
	
	/*int a;
	printf("Input number: ");
	scanf_s("%d", &a);
	printf("- %d - %d - %d\n %d | %d | %d\n- %d - %d - %d\n", a, a, a, a, a, a, a, a, a);*/

	//Task4

	/*float m1, m2, r;
	float gamma = 6.673 * pow(10, -11);

	printf("Input m1: ");
	scanf_s("%f", &m1);
	printf("Input m2: ");
	scanf_s("%f", &m2);
	printf("Input r: ");
	scanf_s("%f", &r);
	
	printf("F => %e", gamma * ((m1 * m2) / pow(r, 2)));*/

	//Task 5

	/*int x;

	printf("Input x: ");
	scanf_s("%d", &x);
	
	printf("a) => %d\n", multiple2operation(x));
	printf("b) => %d\n", multiple3operation(x));
	printf("c) => %d\n", multiple4operation(x));
	printf("d) => %d\n", multiple5operation(x));
	printf("e) => %d\n", multiple6operation(x));
	printf("f) => %llu\n", secondMultiple6operation(x));*/

	//Task 6

	/*int temparature_с;
	printf("enter a: ");
	scanf_s("%d", &temparature_с);

	float temparature_f = (float)(temparature_с * 9) / 5 + 32;
	printf("f=%.0f", temparature_f);*/

	//Task 7

	/*double w;
	printf("Input real x=");
	scanf_s("%lf", &w);

	int w1 = (int)w;
	int w2 = floor(w);
	int w3 = ceil(w);
	int w4 = round(w);

	printf("%d %d %d %d", w1, w2, w3, w4);*/

	//Task 8

	/*double x, y;
	scanf_s("%lf", &x);
	scanf_s("%lf", &y);
	printf("%lf %lf", x - y, x * y);*/

	//Task 9

	/*double x, y;
	printf("Input two numbers: ");
	scanf_s("%lf %lf", &x, &y);
	printf("Arithmetic mean => %lf\n", (x + y) / 2);
	printf("Harmonic mean => %lf\n", 2 / (1 / x + 1 / y));*/

	//Task 18

	/*char TicToeArray[9] = {'X', 'O', 'X', ' ', 'X', 'O', 'O', ' ', ' '};
	
	for (size_t i = 0; i < sizeof(TicToeArray) / sizeof(char); i++) {
		printf("Element: %c \n", TicToeArray[i]);
	}
	printf("%c | %c | %c\n", TicToeArray[0], TicToeArray[1], TicToeArray[2]);
	printf("%c | %c | %c\n", TicToeArray[3], TicToeArray[4], TicToeArray[5]);
	printf("%c | %c | %c\n", TicToeArray[6], TicToeArray[7], TicToeArray[8]);*/


	//Task 21

	/*int a;
	printf("Input number: ");
	scanf_s("%d", &a);
	printf(" - | - | %d | - | - \n - | %d | %d | %d | -\n %d | %d | %d | %d | %d\n", a, a, a, a, a, a, a, a, a); */

	//Task 20
	
	/*double A, B, C;
	printf("A=: ");
	scanf_s("%lf", &A);
	printf("B=: ");
	scanf_s("%lf", &B);
	printf("C=: ");
	scanf_s("%lf", &C);

	printf("Arithmetic mean => %lf\n", (A + B + C) / 3);
	printf("Harmonic mean => %lf\n", 3 / (1 / A + 1 / B + 1 / C));*/
	
	return 0;

}