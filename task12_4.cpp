#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main4() {
    int n;
    cout << "n =>";
    cin >> n;

    int* m = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    const char fname[] = "file1.txt";

    fstream f(fname);

    if (f.bad()) {
        cout << " file " << fname << " could not be opened!\n";
        delete[] m;
        return -1;
    }

    double tmp;
    int* x = new int[n];
    int i = 0;
    while (f >> tmp) {
        x[i++] = tmp;
        if (i > n) break;
    }
    if (i != n) {
        cout << " file " << fname << " has " << i << "data";
        f.close();
        delete[] x;
        delete[] m;
        return -1;
    }

    f.close();

    fstream g("file2.txt");

    for (int i = 0; i < n; i++) {
        g << pow(x[i], m[i]) << " ";
    }


    g.close();
    delete[] x;
    delete[] m;
    return 0;
}