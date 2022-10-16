#include <iostream>
#include <math.h>
#include <stdbool.h>

// Lab 5  5.1-5.7 5.11 b) 5.17 a) 5.19 5.22

const int N = 1000;
int den;
int nom;



//double subfactorial(int N)
//{
//    double res = 0, fact = 1;
//    int count = 0;
//
//    for (int i = 1; i <= N; i++) {
//        fact = fact * i;
//        if (count % 2 == 0)
//            res = res - (1 / fact);
//        else
//            res = res + (1 / fact);
//        count++;
//    }
//    return fact * (1 + res);
//}

void task5() {
    double a;
    printf("a=");
    scanf_s("%lf", &a);

    double s = 0;

    int i = 1;

    while (s < a) {
        s += 1.0 / i;
        i++;
    }

    printf("S (%d) = %lf > %lf", i, s, a);
}

unsigned Fib(unsigned n) {
    unsigned long long F0 = 0, F1 = 1UL, F=1UL;
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    for (unsigned i = 2; i <= n+1; i++) {
        F = F0 + F1;
        F0 = F1;
        F1 = F;
    }

    return F;
}

unsigned FibLess(double a) {
    unsigned long long F0 = 0, F1 = 1UL, F = 1UL;
    if (a < 1) {
        return 0;
    }
    if (a < 2) {
        return 1;
    }

    for (;F<a;) {
        F = F0 + F1;
        F0 = F1;
        F1 = F;
    }

    return F0;
}

int FibV(double a) {
    int n = 1;
    unsigned long long F0 = 0, F1 = 1UL, F = 1UL;
    if (a < 0) {
        return 0;
    }
   

    for (; F < a;) {
        F = F0 + F1;
        F0 = F1;
        F1 = F;
        n++;
    }

    return n;
}

int FibG() {
    unsigned long long F0 = 0, F1 = 1UL, F = 1UL;
    int sum = F0 + F1;
    

    while (F <= 1000) {
        sum += F;
        F = F0 + F1;
        F0 = F1;
        F1 = F;
        
    }

    return sum;
}

int collatz(int k, int n) {
    int ak = n;
    if (k == 0) return ak;
    
    for (int i = 1; i <= k; i++) {
        if (ak % 2 == 0) {
            ak = ak / 2;
        }
        else {
            ak = 3 * ak + 1;
        }
    }

    return ak;
}

double dobutok4a(int n) {
    double P = 1;
    double inv_fact = 1.0;

    for (int i = 1; i < n; i++) {
        inv_fact /= i;
        P *= (1 + inv_fact);
    }

    return P;
}

double dobutok4b(int n) {
    double P = 1;
    for (int i = 1; i < n; i++) {
        P *= (1 + (pow(-1, i + 2) * (pow(i, 2))) / (pow(2,i)));
    }

    return P;
}

int min_positive() {
    int x1 = -99;
    int x2 = -99;
    int x3 = -99;

    int xn = 0;
    int i = 2;
    
    while (xn <= 0) {
        printf("here %d\n", xn);
        xn = x1 + x3 + 100;
        x1 = x2;
        x2 = x3; 
        x3 = xn;
        i++;
    }
    return i;
}


double task6a(int b, unsigned n) {
    if (b <= 0) return 0;

    double res = b;


    for (unsigned i = 1; i <= n; i++) {
        res = b + 1.0 / res;
        /*printf("%lf %d\n", res, i);*/
       
    }

    return res;
}

double task6aa(int b, unsigned n) {
    if (b <= 0) return 0;

    double res = b;

    int nominator = b;
    int denominator = 1;

    for (unsigned i = 1; i <= n; i++) {
        /*res = b + 1.0 / res;*/
        /*printf("%lf %d\n", res, i);*/
        nominator = b * nominator + denominator;
        denominator = nominator;
    }
    nom = nominator;
    den = denominator;

    return 0;
}

double task6b(unsigned n) {
    double res = 4 * n + 2;

    for (unsigned i = n - 1; i != -1; i--) {
        res = 4 * i + 2 + 1.0 / res;
    }

    return res;
}

double task6v(unsigned n) {
    double res = 2;

    for (unsigned i = n; i != 0; i--) {
        if (i % 2 == 0) {
            res = 2 + 1 / res;
        }
        else {
            res = 1 + 1 / res;
        }
        
        /*printf("%lf %d\n", res, i);*/

    }

    return res;
}

double task7(int n) {
    double a1 = 0, a2 = 1, b1 = 1, b2 = 0, ai, bi;

    double S;
    double s1 = 2 / (a1 + b1);
    S = s1;

    if (n == 1) return S;

    S += 4 / (a2 + b2);

    if (n == 2) return S;

    int power2 = 4;
    for (int i = 3; i <= n; i++) {
        bi = a2 + b2;
        ai = a2 / i + a1 * b1;

        power2 *= 2;
        S += power2 / (ai + bi);

        a1 = a2;
        a2 = ai;
        b1 = b2;
        b2 = bi;
    }

    return S;
}

//double Phi(double x, double eps) {
//    double y = x - x * x * x / 3;;
//    int i = 0;
//
//    double dodanok = -x * x * x / 3;
//
//
//    while (fabs(dodanok) > eps) {
//        i++;
//        dodanok *= (-x * x) / (2 * i) / (2 * i + 1) / (2 * i + 3) * (2 * i + 1);
//        y += dodanok;
//    }
//
//    return y;
//}


double task8a(double x, double eps) {
    double sum = 0;
    double power = 1;
    int stup = 2;
    double power_x = x;
    double xi = 1;
    sum += xi;
    
    while (xi >= eps) {
        
        xi = power_x / power;
        sum += xi;
        power_x *= x;
        
        power *= stup;
        stup++; 
    }
    printf("%.20lf", sum);

    return sum;
}

void task8b() {
    double eps, x, sum = 1, index, power = 1, k = 2;

    printf("Input eps, x: ");
    scanf_s("%lf %lf", &eps, &x);

    index = x / power;
    sum += index;

    while (index > eps) {
        k++;
        power *= k;
        index = pow(x, k) / power;
        sum += index;
    }

    printf("Res => %lf", sum);
}

double fun(double x) {
    return tan(x) - x;
}

double rootBisection(double fun(double), double a, double b, double eps) {
    if (fun(a) * fun(b) > 0) return 0;

    double c = (a + b) / 2;
    if (b - a < eps) {
        return c;
    }

    if (fun(a) * fun(c)<0) {
        return rootBisection(fun, a, c, eps);
    }
    return rootBisection(fun, b, c, eps);

}

double ak_task11(int k) {
    if (k == 1 || k == 2) return 1;
    else {
        return ak_task11(k - 1) / k + ak_task11(k - 2);
    }
}

void task11b() {
    int n , k;
    double sum = 0;

    printf("Input n: ");
    scanf_s("%d", &n);
    
    for (k = 1; k <= n; k++) {
        sum += pow(3, k) / ak_task11(k);
    }

    printf("Res => %lf", sum);
}

void task17a() {
    double eps, x, sum = 1, index, count = 2;
    int k = 2, factorial = 1;
    printf("Input eps, x: ");
    scanf_s("%lf %lf", &eps, &x);
    
    index = pow(x, 2) / 2;
    sum += index;
   
    while (index > eps) {
        count++;
        factorial *= k;
        index = pow(x, 2 * k) / (2 * factorial);
        sum += index;

        k++;
    }

    printf("Res => %lf %lf", sum, count);
}

void task19() {
    double left = -0.001, right = 1.5, eps = 0.00001, medium;
    //Proof
    /*double left_p = 0.001, right_p = 1.5, delta_x = 0.001;
    bool check = false;
    for (double i = left_p; i < right_p; i += delta_x) {
        if ((tan(i) - i) * (tan(right_p) - right_p) < 0)
            check = true;
    }
    if (check) {
        printf("There is a root");
    }
    else {
        printf("There is no a root");
    }*/
    
    while (right - left > eps) {
        medium = (right + left) / 2;
        printf("Medium => %lf\n", medium);
        if ((tan(left) - left) * (tan(medium) - medium) > 0) {
            
            left = medium;
            printf("Left => %lf\n", left);
        }
        else if ((tan(right) - right) * (tan(medium) - medium) > 0) {
            
            right = medium;
            printf("Right => %lf\n", right);
        }
    }


    printf("Res => %.40lf",medium);
}

double task22_a(int k);

double task22_b(int k);

double task22_t(int k);

double task22_p(int k);

void task22() {
    int k;
    double pi;

    printf("Input k: ");
    scanf_s("%d", &k);
    /*printf("test 1 => %lf\ntest 2 => %lf\ntest 3 => %lf\ntest 4 => %lf\n", task22_a(k),
        task22_b(k), task22_t(k), task22_p(k));*/

    pi = pow(task22_a(k) + task22_b(k), 2) / (4 * task22_t(k));

    printf("Res => %lf", pi);
}

int main()
{
    /*int N = 24;
    printf("%lf", subfactorial(N));*/

    //1
    /*task5();*/

    //2
    /*unsigned n;
    printf("n=");
    scanf_s("%u", &n);
    
    printf("F(%u) = %u\n",n, Fib(n));

    unsigned a;
    printf("a=");
    scanf_s("%u", &a);

    printf("F(%u) = %u < %lf", n, FibLess(a), a);*/

    /*printf("%d", FibG());*/

    //3
    //int n = 9;
    //
    //for (int i = 1; i < 5; i++) {
    //    printf("a[%d] = %d\n", i , collatz(i, n));
    //}
    //int MaxI = 0;
    //int MaxJ = 0;
    //for (int j = 1; j < N; j++) {

    //    int a1 = collatz(1, j);
    //    int i = 1;
    //    while (a1 != 1) {
    //        i++;
    //        a1 = collatz(i, j);
    //        
    //        if (i > 100000) {
    //            printf("we break the conjecture!");
    //            break;
    //        }
    //        //printf("a[%d] = %d\n", i, collatz(i, n));
    //    }
    //    printf("I = %d\n", i);

    //    if (i > MaxI) {
    //        MaxI = i;
    //        MaxJ = j;
    //    }

    //    

    //}
    //printf("\nMaxI = %d for j = %d\n", MaxI, MaxJ);
    //int a2 = MaxJ;
    //int i = 0;

    //while (a2 != 1) {
    //    i++;
    //    a2 = collatz(i, MaxJ);
    //    printf("%d, ", a2);
    //}

    //4
    /*printf("%lf", dobutok4a(5));*/
    /*printf("%lf", dobutok4b(5));*/

    //5
    /*printf("Res => %d", min_positive());*/
    
    //8
    /*task8b();*/

    //6
    /*int b;
    unsigned n;
    printf("b,n: ");
    int r = scanf_s("%d %u", &b, &n);
    if (r != 2) {
        printf("Input accuartely!!!");
        return -1;
    }
    printf("B=%lf", task6v( n));*/

    /*task6aa(b, n);
    printf("B=%d / %d", nom , den);*/

   /* double x, eps;
    printf("Input x:");
    scanf_s("%lf", &x);

    do {
        printf("Input positive eps:");
        scanf_s("%lf", &eps);
    } while (eps <= 0);*/

    /*printf("Phi(%g) = %lf", x, Phi(x, eps));*/
    /*task8a(x, eps);*/
    
    /*double a = 0.01;
    double b = 1.8;
    double eps = 1e-5;

    printf("root: %lf", rootBisection(fun, a, b, eps));*/

    //11 b)
    /*task11b();*/

    //17 a)
    /*task17a();*/

    //19
    /*task19();*/

    //22
    /*task22();*/

    return 0;
}

double task22_a(int k) {
    if (k == 0) return 1;
    else {
        return (task22_a(k - 1) + task22_b(k - 1)) / 2;
    }
}

double task22_b(int k) {
    if (k == 0) return 1 / sqrt(2);
    else {
        return sqrt(task22_a(k - 1) * task22_b(k - 1));
    }
}

double task22_t(int k) {
    if (k == 0) return 0.25;
    else {
        return task22_t(k - 1) - task22_p(k - 1) * pow((task22_a(k - 1) - task22_a(k)), 2);
    }
}

double task22_p(int k) {
    if (k == 0) return 1;
    else {
        return 2 * task22_p(k - 1);
    }
}