//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector <string> func_1(string a, int b, string c)
//{
//    vector <string> d;
//
//    while ((d.size() < b))
//    {
//        string ttemp = "";
//        int end = a.find(c);
//        if (end == -1)
//        {
//            d.push_back(a);
//            return d;
//        }
//        for (int i = 0; i < end; i++)
//        {
//            ttemp += a[i];
//        }
//        d.push_back(ttemp);
//        a.erase(0, end + c.length());
//    }
//    return d;
//}
//
//
//int main()
//{
//    string a;
//    unsigned int b;
//    string c;
//    cout << "Print smth:" << endl;
//    getline(cin, a);
//    cout << "Number:" << endl;
//    cin >> b;
//    cout << "Space:" << endl;
//    cin >> c;
//    vector <string> m = func_1(a, b, c);
//    for (auto h : m)
//    {
//        cout << h << endl;
//    }
//}