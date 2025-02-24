#include <iostream>

using namespace std;

class Triangle{
private:
        double ax, ay;
        double bx, by;
        double cx, cy;
public:
        Triangle(double ax, double ay, double bx, double by, double cx, double cy){
            if ((ax == bx & ay == by) | (ax == cx & ay == cy) | (cx == bx & cy == by)){
                cout << "Triangle is not exist!" << "\n";
                return ;
            }
        }
};

int main(){
    double ax, ay, bx, by, cx, cy;
    cout << "Enter the coordinates of the points" << "\n";
    cout << "Point A: ";
    cin >> ax >> ay;
    cout << "Point B: ";
    cin >> bx >> by;
    cout << "Point C: ";
    cin >> cx >> cy;
    Triangle t(ax, bx, cx, ay, by, cy);
    return 0;
}
