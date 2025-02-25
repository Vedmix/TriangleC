#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int existError(){
    cout << "Triangle is not exist!" << "\n";
    exit(0);
}

class Triangle{
private:
        double ax, ay;
        double bx, by;
        double cx, cy;
        vector<double> lengthSidesTriangle() {
            double ab = sqrt(pow((bx - ax), 2) + pow((by - ay), 2));
            double bc = sqrt(pow((cx - bx), 2) + pow((cy - by), 2));
            double ac = sqrt(pow((cx - ax), 2) + pow((cy - ay), 2));

            return {ab, bc, ac};
        }

public:
        Triangle(double x1, double y1, double x2, double y2, double x3, double y3):
        ax(x1), ay(y1), bx(x2), by(y2), cx(x3), cy(y3) {
            if ((ax == bx & ay == by) | (ax == cx & ay == cy) | (cx == bx & cy == by)){
                existError();
            }
        }
        void printInfo() {
            vector<double> sides = lengthSidesTriangle();
            cout << "AB: " << sides[0] << "\n";
            cout << "BC: " << sides[1] << "\n";
            cout << "AC: " << sides[2] << "\n";
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

    t.printInfo();
    return 0;
}
