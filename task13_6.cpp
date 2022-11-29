//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector <string> func_1(string a)
//{
//    vector <int> c;
//    for (int d = 0; d < a.length(); d++)
//    {
//        //cout << a[d] << endl;
//        if (a[d] == ' ')
//        {
//            c.push_back(d);
//        }
//    }
//
//    vector <string> b;
//
//    if (c[0] != 0)
//    {
//        string ttemp = "";
//        for (int j = 0; j < c[0]; j++)
//        {
//            ttemp += a[j];
//        }
//        b.push_back(ttemp);
//    }
//
//    for (int i = 1; i < c.size(); i++)
//    {
//        if ((c[i] - c[i - 1]) > 1)
//        {
//            string ttemp = "";
//            for (int j = c[i - 1] + 1; j < c[i]; j++)
//            {
//                ttemp += a[j];
//            }
//            b.push_back(ttemp);
//        }
//    }
//
//    if (c[c.size() - 1] != (a.length() - 1))
//    {
//        string ttemp = "";
//        for (int j = c[c.size() - 1] + 1; j < a.length(); j++)
//        {
//            ttemp += a[j];
//        }
//        b.push_back(ttemp);
//    }
//    return b;
//}
//
//
//
//
//int main()
//{
//    string a;
//    int n;
//    cout << "Print smth:" << endl;
//    getline(cin, a);
//    vector <string> g = func_1(a);
//    string ttmp = g[0];
//    cout << "A" << endl;
//    int l = 0;
//    for (int h = 1; h < g.size(); h++)
//    {
//        if (!(ttmp.length() < g[h].length()))
//        {
//            if (ttmp.length() == g[h].length())
//            {
//                l += 1;
//            }
//            else
//            {
//                ttmp = g[h];
//                l = 0;
//            }
//        }
//    }
//    cout << ttmp << endl;
//    if (l)
//    {
//        cout << "B" << endl;
//        for (int i = g.size() - 1; i >= 0; i--)
//        {
//            if (g[i].length() == ttmp.length())
//            {
//                cout << g[i] << endl;
//                break;
//            }
//        }
//        if (l > 1)
//        {
//            cout << "C" << endl;
//            for (string j : g)
//            {
//                if (j.size() == ttmp.size())
//                {
//                    cout << j << endl;
//                }
//            }
//        }
//    }
//}