//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//string func_1(string a)
//{
//    vector <int> b;
//    int ttemp = 0;
//    for (int j = 0; j < a.size(); j++)
//    {
//        if ((a[j] != ' ') && (ttemp == 0))
//        {
//            ttemp = 1;
//        }
//        if ((a[j] == ' ') && (ttemp == 1))
//        {
//            b.push_back(j - 1);
//            ttemp = 0;
//        }
//    }
//    string c = a;
//    for (int k = b.size() - 1; k >= 0; k--)
//    {
//        c.erase(b[k], 1);
//    }
//    return c;
//}
//
//void func_2(string* a)
//{
//    vector <int> b;
//    int ttemp = 0;
//    for (int j = 0; j < a->size(); j++)
//    {
//        if (((*a)[j] != ' ') && (ttemp == 0))
//        {
//            ttemp = 1;
//        }
//        if (((*a)[j] == ' ') && (ttemp == 1))
//        {
//            b.push_back(j - 1);
//            ttemp = 0;
//        }
//    }
//    for (int k = b.size() - 1; k >= 0; k--)
//    {
//        a->erase(b[k], 1);
//    }
//}
//
//int main()
//{
//    string a;
//    cout << "Input => " << endl;
//    getline(cin, a);
//    string b = func_1(a);
//    cout << b << endl;
//    func_2(&a);
//    cout << a << endl;
//}