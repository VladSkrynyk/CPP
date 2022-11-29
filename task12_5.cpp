#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main5() {
    char fname[255];

    cout << "file name =>";
    cin >> fname;

    fstream f;
    f.open(fname);

    if (!f) {
        return -1;
    }

    long long unsigned mas[2000];
    int i = 0;
    while (f >> mas[i]) {
        i++;
    }

    f.close();

    for (int j = i - 1; j >= 0; j--) {
        double tmp = sqrt(mas[i]);
        cout.precision(4);
        cout << tmp << "\n";
    }

    return 0;
}