#include <iostream>
#include <cmath>

using namespace std;

class Triangle{
private:
        double ax, ay;
        double bx, by;
        double cx, cy;
        double ab(){
            return sqrt((pow((bx - ax), 2) + pow((by - ay), 2)));
        }
        double bc(){
            return sqrt((pow((cx - bx), 2) + pow((cy - by), 2)));
        }
        double ac(){
            return sqrt((pow((cx - ax), 2) + pow((cy - ay), 2)));
        }
public:
        Triangle(double x1, double y1, double x2, double y2, double x3, double y3):
        ax(x1), ay(y1), bx(x2), by(y2), cx(x3), cy(y3) {
            if ((ax == bx & ay == by) | (ax == cx & ay == cy) | (cx == bx & cy == by)){
                cout << "Triangle is not exist!" << "\n";
                return ;
            }
        }
        void sides(){
            cout << ab() << "\n";
            cout << bc() << "\n";
            cout << ac() << "\n";
        }


};

int main(){
    double x1, y1, x2, y2, x3, y3;
    cout << "Enter the coordinates of the points" << "\n";
    cout << "Point A: ";
    cin >> x1 >> y1;
    cout << "Point B: ";
    cin >> x2 >> y2;
    cout << "Point C: ";
    cin >> x3 >> y3;
    cout << "\n";
    Triangle t(x1, y1, x2, y2, x3, y3);

    t.sides();
    return 0;
}
