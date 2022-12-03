#include <iostream>
//#include <string>
//#include <cmath>
//using namespace std;
//
//class Point {
//    private:
//    double x;
//    double y;
//    public:
//    Point(){
//        this->x = 0;
//        this->y = 0;
//    }
//
//    Point(double x, double y){
//        this->x = x;
//        this->y = y;
//    }
//
//    void show() cout << "(" << this->x << "," << this->y << ")" << endl;
//    
//
//    int input(){
//        cout << "x, y = ";
//        cin >> this->x >> this->y;
//        return 0;
//    }
//
//    double compute_distance(Point other){
//        return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
//    }
//};
//
//int main(){
//    Point current = Point(5, 4);
//    Point before;
//    Point starter;
//    int counter = 0;
//    double perimeter;
//    char input;
//    do{
//        counter += 1;
//        current.input();
//        current.show();
//        if (counter == 1) starter = current;
//        else{
//            double dist = before.compute_distance(current);
//            perimeter += dist;
//        }
//        before = current;
//        cout << "Continue ? ";
//        cin >> input;
//    } while (input != 'n');
//    perimeter += starter.compute_distance(current);
//
//    cout << endl << "Nodes - " << counter << endl;
//    cout << "Perimeter " << perimeter;
//    return 0;
//}