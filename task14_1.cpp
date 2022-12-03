//#include <iostream>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//
//void get_result(string name) {
//    
//    fstream f;
//    f.open(name);
//    string a;
//    getline(f, a);
//    f.close();
//
//    int sum = 0;
//    int temp = 0;
//    int ttmp = 0;
//    string sub = "";
//    for (char b : a) {
//        if ((b != '+') && (b != '-') && (b != '=')) {
//            sub += b;
//        }
//        else {
//            if (ttmp == 0) {
//                sum += stoi(sub);
//                ttmp = 1;
//                if (b == '-') { temp = -1; }
//                if (b == '+') { temp = 1; }
//                sub = "";
//            }
//            else {
//                if (temp == -1) sum -= stoi(sub);
//                if (temp == 1) sum += stoi(sub);
//
//                sub = "";
//                if (b == '-') { temp = -1; }
//                if (b == '+') { temp = 1; }
//                if (b == '=') { temp = 0; break; }
//            }
//        }
//        if (b == '=') break;
//    }
//
//    cout << sum << endl;
//}
//
//int main11() {
//    string a;
//    cout << "Input filename => ";
//    cin >> a;
// 
//    get_result(a);
//}