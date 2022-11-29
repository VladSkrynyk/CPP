#include <iostream>
#include <cmath>

using namespace std;

int main1() {
    double x, y;

    cout << "Input x:";
    cin >> x;
    cout << "Input y:";
    cin >> y;

    double z = pow(x, y);
    cout << "x**y : " << scientific << z;

    return 0;
}