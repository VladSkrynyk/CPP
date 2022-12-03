//#include <iostream>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//
//void get_result(string name, char n) {
//    fstream f;
//    f.open(name, ios::in);
//
//    vector <string> a;
//    string temp;
//
//    unsigned int start = 0;
//    unsigned int end = 0;
//    unsigned int similar = 0;
//    unsigned int all = 0;
//
//    while ((!f.eof())) {
//        getline(f, temp);
//        if (temp[0] == n) start++;
//        if (temp[temp.size() - 1] == n) end++;
//        if (temp[temp.size() - 1] == temp[0]) similar++;
//
//        int htem = 1;
//        char f = temp[0];
//        for (char g : temp){
//            if (g != f){
//                htem = 0;
//                break;
//            }
//        }
//        if (htem)
//            all++;
//    }
//    f.close();
//    cout << start << " starts => " << n << endl;
//    cout << end << " ends => " << n << endl;
//    cout << similar << " start and end " << endl;
//    cout << all << " one char " << endl;
//}
//
//
//
//int main() {
//    string h;
//    cout << "Input character => ";
//    cin >> h;
//
//    get_result("test14_5_input.txt", h[0]);
//}
