//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector <double> func_1(string a, int b, string c)
//{
//    int counter = 0;
//    vector <double> d;
//    while (d.size() < b)
//    {
//        int end = a.find(c);
//        if (end == -1)
//        {
//            return d;
//        }
//        string temp = "";
//        for (int j = 0; j < end; j++)
//        {
//            temp += a[j];
//        }
//        d.push_back(stod(temp));
//        a.erase(0, end + c.size() - 1);
//    }
//    return d;
//}
//
//
//int main()
//{
//    string a, b;
//    int n;
//    cout << "Print smth:" << endl;
//    getline(cin, a);
//    cout << "Number of elements to read:" << endl;
//    cin >> n;
//    cout << "Substr:" << endl;
//    getline(cin, b);
//    vector <double> h = func_1(a, n, b);
//
//    for (auto m : h)
//    {
//        cout << m << endl;
//    }
//}