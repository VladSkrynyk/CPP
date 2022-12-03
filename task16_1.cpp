//#include <iostream>
//#include <fstream>
//#include <cstdio>
//#include <string>
//using namespace std;
//
//class Person{
//protected:
//    string name;
//    unsigned byear;
//public:
//    int input();
//    void show();
//};
//
//int Person::input(){
//    cout << "Input person(name, year):\n";
//    cin >> name;
//    cin >> byear;
//    return 0;
//}
//
//void Person::show() cout << "Person" << name << ", " << byear;
//
//
//class Acquanted : public Person{
//private:
//    string tel;
//public:
//
//    int getTel(string s){
//        tel = s;
//        return 0;
//    }
//
//    string getName() return name;
//
//
//    void show() cout << "Acquinted " << name << ", " << byear << ", " << tel;
//
//
//    int input(){
//        Person::input();
//        cout << "phone";
//        cin >> tel;
//        return 0;
//    }
//};
//
//class Phonebook{
//    string filename;
//    fstream fp;
//public:
//
//    int setFile(string s){
//        filename = s;
//        return 0;
//    }
//
//    int startNew() return remove(filename.c_str());
//
//
//    int addAcquanted(Acquanted& x){
//        fp.open(filename.c_str(), ios::app | ios::binary);
//        if (fp.bad){
//            cerr << "error opening " << filename;
//            return -1;
//        }
//        fp.write((char*)&x, sizeof(x));
//        fp.close();
//        return 0;
//    }
//
//    int addAcquanted2(Acquanted& x){
//        FILE* fp = fopen(filename.c_str(), "ab");
//        if (fp == NULL){
//            cerr << "error opening " << filename;
//            return -1;
//        }
//        fwrite((char*)&x, sizeof(x), 1, fp);
//        fclose(fp);
//        return 0;
//    }
//
//    string getTelByName(string name){
//        fp.open(filename.c_str(), ios::in | ios::binary);
//        if (fp.bad){
//            cerr << "error opening " << filename;
//            return "Error";
//        }
//        cout << "\n";
//        Acquanted* x = new Acquanted();
//        while (!fp.eof()) {
//            fp.read((char*)x, sizeof(*x));
//            cout << "working";
//            cout << "\np=";
//            x->show();
//            if (x->getName() == name) {
//                cout << "Found " << name;
//                fp.close();
//                return x->getTel();
//            }
//        }
//        fp.close();
//        cout << "Not found";
//        return string("None");
//    }
//
//    string getTelByName2(string name) {
//        FILE* fp = fopen(filename.c_str(), "rb");
//        if (fp == NULL){
//            cerr << "error opening " << filename;
//            return "Error";
//        }
//        cout << "\n\n\n";
//        Acquanted y;
//        Acquanted* x = &y;
//        while (!feof(fp)){
//            cout << "working" << fread(x, sizeof(*x), 1, fp);
//            cout << "\np=";
//            x->show();
//            if (x->getName() == name){
//                cout << "Found " << name;
//                fclose(fp);
//                string res = x->getTel();
//                return res;
//            }
//        }
//        fclose(fp);
//        cout << "Not found";
//        return string("None");
//    }
//};
//
//int main()
//{
//    Person p;
//    Phonebook ph;
//    ph.setFile(string("file.dat"));
//    ph.startNew();
//    int n;
//    cout << "n = ";
//    cin >> n;
//    Acquanted a;
//    for (int i = 0; i < n; i++)
//    {
//        a.input();
//        a.show();
//        ph.addAcquanted(a);
//    }
//    string t = ph.getTelByName("Vlad");
//    cout << t;
//}