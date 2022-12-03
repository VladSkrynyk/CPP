//#ifndef __RATTIO__
//#define __RATTIO__
//#include <iostream>
//
//class Ratio
//{
//private:
//    int nom;
//    unsigned den;
//public:
//
//    Ratio(int x, unsigned y) :nom(x), den(y) {}
//    Ratio() :nom(0), den(1) {}
//
//    void reduce(){
//        unsigned g = gcd(nom, den);
//        nom /= g;
//        den /= g;
//    }
//
//    void setNom(int x){
//        nom = x;
//    }
//
//    void show(){
//        std::cout << nom << "/" << den << "\n";
//    }
//
//    bool input(){
//        std::cout << "nom/den:";
//        int x;
//        unsigned y;
//        std::cin >> x;
//        std::cin >> y;
//        setNom(x);
//        if (!setDen(y)){
//            den = 1;
//            return false;
//        }
//        return true;
//    }
//
//    Ratio add(Ratio x);
//
//    Ratio mult(const Ratio& x);
//
//    friend std::ofstream& operator<<(std::ostream& x, const Ratio& y){
//        x << y.nom << "/" << y.den;
//        return x;
//    }
//
//    friend std::ofstream& operator<<(std::istream& x, const Ratio& y){
//        x >> y.nom >> "/" >> y.den;
//        return x;
//    }
//
//    Ratio operator+(const Ratio& x){
//        return add(x);
//    }
//
//private:
//    unsigned gcd(unsigned x, unsigned y);
//};
//
//#endif //__RATIO__
//#include "Ratio.h"
//
//Ratio hregory(double eps) {
//    Ratio r;
//    r.setNom(1);
//    int i = 1;
//    while (i * i * eps < 1)
//}
//
//int main() {
//    Ratio a1(1, 2), a2, a3;
//    std::cin >> a2;
//    a3 = a1 + a2;
//    a3.reduce();
//}