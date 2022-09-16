#include <stdio.h>
#include <math.h>
#define PI 3.141592654
// Laba 2 2.1.-2.6   2.4e   2.14    2.17j

double heron(double a, double b, double c) {
   return sqrt((a + b + c) * (a + b - c) * (a + c - b) * (b + c - a)) / 4;
}

double gethypotenuse(double a, double b) {
    
    return sqrt(a * a + b * b);
}

double task4a(double x) {
    double y = x * x + 1;
    return y * y;
}

double task4b(double x) {
    double x1 = x + 1;
    return pow(x, 3) * x1 + x * x1 + 1;
}

double task4c(double x) {
    double x4 = pow(x, 4);
    double x2 = pow(x, 2);
    return x4 * (x + 5) + x2 * (10 *x + 10) + 5 * x + 1;
}

double task4g(double x) {
    double x3 = pow(x, 3);
    return x3 * x3 * x3 + x3 + 1;
}

double task4d(double x) {
    double x2 = pow(x, 2);
    double x3 = pow(x, 3);
    double x4 = pow(x, 4);
    return 16 * x4 + 8 * x3 + 4 * x2 + 2 * x + 1;
}

double my_task4e(double x) {
    double x2 = x * x;
    double x4 = x2 * x2;
    return x * (x4 + x2 + 1);
}

double Rosenbrock2d(double x, double y) {
    double z = x * x - y;
    return 100 * z * z + (x - 1) * (x - 1);
}

double length(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double invsqrt(double x, double alpha) {
    return x / sqrt(1 + alpha * pow(x, 2));
}

double invsqrt_derivative(double x, double alpha) {
    return (sqrt(1 + alpha * pow(x, 2)) - (alpha * pow(x, 2) / sqrt(1 + alpha * pow(x, 2)))) / (1 + alpha * pow(x, 2));
}

int main()
{
    //Task 1

    /*double arg;
    printf("Input arg:");
    scanf_s("%lf", &arg);
    printf("cos of %.2lf => %.2lf", arg, cos(arg));*/

    //Task 2

    /*float a, b;
    printf("input a b = ");
    scanf_s("%f %f", &a, &b);
    printf("Hypotenuse => %f", sqrt(pow(a, 2) + pow(b, 2)));*/

    /*float a, b, c;
    printf("input a b = ");
    scanf_s("%f %f", &a, &b);

    printf("Hypotenuse => %f", gethypotenuse(a, b));*/

    //Task 3

    /*float a, b, c;
    printf("input a b c = ");
    scanf_s("%f %f %f", &a, &b, &c);
    double S = heron(a, b, c);
    printf("S => %f", S);*/
    
    //Task 4
    
    //a
    /*float x;
    printf("input x = ");
    scanf_s("%f", &x);
    printf("Result => %f", task4a(x));*/

    //b
    /*float x;
    printf("input x = ");
    scanf_s("%f", &x);
    printf("Result => %f", task4b(x));*/

    //c
    /*float x;
    printf("input x = ");
    scanf_s("%f", &x);
    printf("Result => %f", task4c(x));*/

    //g
    /*float x;
    printf("input x = ");
    scanf_s("%f", &x);
    printf("Result => %f", task4g(x));*/

    //d
    /*float x;
    printf("input x = ");
    scanf_s("%f", &x);
    printf("Result => %f", task4d(x));*/

    //e
    /*float x;
    printf("input x = ");
    scanf_s("%f", &x);
    printf("Result => %f", my_task4e(x));*/

    //Task 5

    /*double x;
    printf("x=");
    scanf_s("%lf", &x);

    printf("y=%lf\n", task4a(x));

    printf("%lf", Rosenbrock2d(0, 0));

    if (fabs(Rosenbrock2d(1, 0) + 100) > 0.0000001) {
        printf("error task 1!");
    }

    if (fabs(Rosenbrock2d(2, 4) + 1) < 0.0000001) {
        printf("error task 2!");
    }*/

    //Task 6

    /*double x1, y1, x2, y2, x3, y3;

    printf("Input A(x, y):\n");
    scanf_s("%lf %lf", &x1, &y1);
    printf("Input B(x, y):\n");
    scanf_s("%lf %lf", &x2, &y2);
    printf("Input C(x, y):\n");
    scanf_s("%lf %lf", &x3, &y3);

    double a = length(x1, y1, x2, y2);
    double b = length(x2, y2, x3, y3);
    double c = length(x3, y3, x1, y1);

    printf("S => %f", heron(a, b, c));*/

    //Task 14
    /*float D, a = 3, b = 100, c = 2;
    D = pow(b, 2) - 4 * a * c;
    printf("Result 1 => %f\nResult 2 => %f", (-1 * b + sqrt(D)) / 2 * a, (-1 * b - sqrt(D)) / 2 * a);*/

    //Task 17
    /*float x, alpha;
    printf("input x alpha: ");
    scanf_s("%f %f", &x, &alpha);
    printf("Result 1 => %f\n", invsqrt(x, alpha));
    printf("Result 2 => %f", invsqrt_derivative(x, alpha));*/

    return 0;
}