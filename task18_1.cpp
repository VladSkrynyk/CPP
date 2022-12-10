#include <iostream>
#include <cstdint>
#include <type_traits>
#include <typeinfo>

class Ratio{
public:
    int ch;
    int zn;
    Ratio(int a, int b) {
        this->ch = a;
        this->zn = b;
    }

};

template < typename P, typename Q>
auto
compare(P p, Q q) {
    using T = typename std::common_type< P, Q >::type;
    T promoted_p{ p };
    T promoted_q{ q };

    std::cout << "Type 1: " << typeid(p).name() << "\n";
    std::cout << "Type 2: " << typeid(q).name() << "\n";

    if (promoted_p < promoted_q) {
        return -1;
    }
    else if (promoted_p > promoted_q) {
        return 1;
    }
    else {
        return 0;
    }
}

template < typename Ratio>
auto
compare(Ratio p, Ratio q) {
    using T = typename std::common_type< Ratio >::type;
    T promoted_p{ p };
    T promoted_q{ q };
    
    std::cout << "Type 1: " << typeid(p).name() << "\n";
    std::cout << "Type 2: " << typeid(q).name() << "\n";
    double p1 = promoted_p.ch / promoted_p.zn;
    double p2 = promoted_q.ch / promoted_q.zn;
    
    if (p1 < p2) {
        return -1;
    }
    else if (p1 > p2) {
        return 1;
    }
    else {
        return 0;
    }
}

int main1() {
    Ratio a(1, 2);
    Ratio b(2, 2);

    if (compare(a, b) != 1) {
        std::cout << "2 is bigger\n";
    }
    else {
        std::cout << "1 is bigger\n";
    }

    return 0;
}