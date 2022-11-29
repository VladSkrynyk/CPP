#include <iostream> 

using namespace std;

string f1(string a) {
    int b = a.find(':');
    int c = a.find(',');
    if (b == -1) {
        return a;
    }
    else {
        string d = "";
        if (c == -1) {
            for (int g = b + 1; g < a.length(); g++) {
                d += a[g];
            }
            return d;
        }
        else {
            for (int g = b + 1; g < c; g++) {
                d += a[g];
            }
            return d;
        }

    }

}


void f2(string* a) {
    int b = a->find(':');
    int c = a->find(',');
    if (b == -1) {
        // return *a;
    }
    else {
        string d = "";
        if (c == -1) {
            for (int g = b + 1; g < a->length(); g++) {
                d += (*a)[g];
            }
            *a = d;
            //return d;
        }
        else {
            for (int g = b + 1; g < c; g++) {
                d += (*a)[g];
            }
            *a = d;
            //return d;
        }

    }

}

int main11() {
    string a;
    cout << "Input =>" << endl;
    cin >> a;
    string b = f1(a);
    cout << b << endl;
    f2(&a);
    cout << a << endl;

    return 0;
}