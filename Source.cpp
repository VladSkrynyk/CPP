#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdint.h>
#include <inttypes.h>

//4.1-4.10  4.19 b)  4.27 j) e)

void task1() {
	unsigned i,n;
	float x,y;

	printf("x= ");
	scanf_s("%f", &x);

	printf("n= ");
	scanf_s("%u", &n);

	y = x;

	for (i = 0; i < n; i++) {
		y = sin(y);
	}

	printf("y=%f", y);
}

void task2() {
	unsigned i, n;
	
	printf("n= ");
	scanf_s("%u", &n);

	printf("%u! = ", n);
	for (i = n; i > 0; i--) {
		if (i == 1) {
			printf("%d", i);
			break;
		}
		printf("%d*", i);
	}
	printf("\n");

	printf("%u! = ", n);
	for (i = 1; i <= n; i++) {
		if (i == n) {
			printf("%d", i);
			break;
		}
		printf("%d*", i);
	}
	printf("\n");
}

void task3a() {
	unsigned i, n;
	float x, y, power;

	printf("n=");
	scanf_s("%u", &n);

	printf("x=");
	scanf_s("%f", &x);

	y = 1;
	power = 1;

	for (i = 0; i < n; i++) {
		power *= x;
		printf("%lf\n", power);
		y += power;
	}

	printf("y=%f", y);
}

void task3b() {
	unsigned n = 4, x = 1, y = 2;
	double sum = 0;
	for (int i = n; i >= 0; i--) {
		sum += pow(x, 2 * pow(2, i)) * pow(y, i);
	}
	printf("%lf", sum);
}

void task4(int n, double x) {
	double sum = 0;
	
	for (int i = 1; i <= n; i++) {
		sum += i * pow(x, i);
	}

	printf("Res => %lf", sum);
}

void task5(int n) {
	int sum = 1;
	if (n % 2 == 0) {
		int i = 2;
		for (i; i <= n; i += 2) {
			sum *= i;
		}
	}
	else {
		int i = 1;
		for (i; i <= n; i += 2) {
			sum *= i;
		}
	}

	printf("Res => %d", sum);
}

void task7() {
	unsigned i, n;
	float x, y, a;

	printf("x= ");
	scanf_s("%f", &x);

	printf("n= ");
	scanf_s("%u", &n);

	y = 1;
	a = 1;

	for (unsigned i = 1; i <= n; i++) {
		a *= (x / i); // a = x^i / i!
		y += a;
	}

	printf("y=%lf", y);

}

void task8() {
	unsigned m, n;
	float x, y, a;

	x = 1;
	m = 0;
	
	printf("n= ");
	scanf_s("%u", &n);

	while (x < n) {
		x *= 4;
		m++;
	}

	printf("m=%u", m - 1);
}

void task9() {
	unsigned m, n;
	float r;

	r = 1;
	m = 0;

	printf("n= ");
	scanf_s("%u", &n);

	 do {
		r *= 2;
		m++;
	 } while (r < n);

	printf("m=%u", m);
}

void task10() {
	double a = 1;
	while (1 + a != 1) {
		a = a / 2;
	}
	printf("%.20lf", a);
}

void task11() {
	int i = 0, n = 0;
	double a, sum_a = 0, harm_a = 0;

	do {
		printf("a[%d]", i);
		scanf_s("%lf", &a);
		sum_a += a;
		harm_a += 1 / a;
		i++;
	} while (a != 0);
	
	sum_a /= i;
	harm_a = 1 / harm_a;

	printf("Average => %lf, Harmonical => %lf", sum_a, harm_a);
}

void task19_b() {
	unsigned n;
	double res = 1;

	printf("Input n: ");
	scanf_s("%u", &n);

	while (n <= 2) {
		printf("!!! n must be > 2!!! \n");

		printf("Input n: ");
		scanf_s("%u", &n);
	}
	
	for (int i = 2; i <= n; i++) {
		res *= 1 - (1 / pow(i, 2));
	}

	printf("Res => %lf", res);

}

void task27_j() {
	double eps, sum1 = 0, sum2 = 0, index1 = 1, index2 = 1;
	double m = 1, k = 1;

	printf("Input eps: ");
	scanf_s("%lf", &eps);

	while (index1 > eps) {
		printf("start\n");
		while (index2 > eps) {
			index2 = 1.0 / pow((4 * m - 2), k);
			
			sum2 += index2;
			m++;
		}
		printf("end\n");
		k++;
		m = 1;
		index1 = sum2;
		sum1 += sum2;
		printf("%lf\n", sum1);
		sum2 = 0;
	}

	printf("Res => %lf", 8 * sum1);
}

void task27_e() {
	double eps, sum = 0, index = 1;
	double k = 1;

	printf("Input eps: ");
	scanf_s("%lf", &eps);
	
	while (fabs(index) > eps) {
		sum += index;
		index = pow(-1, k) / (pow(3, k) * (2 * k + 1));
		k++;
	}

	printf("Res => %lf", 2 * sqrt(3) * sum);
}

int main() {
	//1
	/*task1();*/

	//2
	/*task2();*/

	//3
	/*task3a();*/
	/*task3b();*/

	//4
	/*int n;
	double x;

	printf("Input n: ");
	scanf_s("%d", &n);

	printf("Input x: ");
	scanf_s("%lf", &x);

	task4(n, x);*/

	//5
	/*int n;

	printf("Input n: ");
	scanf_s("%d", &n);

	task5(n);*/

	//6
	/*int n = 2;
	double s = sqrt(2);
	for (int i = 1; i < n; i++) {
		s = sqrt(s + 2);
	}
	printf("%lf", s);

	unsigned n, i;
	float sq, koef;

	printf("n =");
	scanf_s("%u", &n);

	koef = 3 * n;
	sq = sqrt(koef);
	for (i = 2; i < n; i++) {
		koef -= 3;
		sq = sqrt(koef + sq);
	}
	printf("%f", sq);*/

	//7
	/*task7();*/

	//8
	/*task8();*/

	//9
	/*task9();*/

	//10
	/*task10();*/

	//19 b)
	/*task19_b();*/

	//27 j) e)
	/*task27_j();*/
	/*task27_e();*/


}