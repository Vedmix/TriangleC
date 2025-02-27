#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int existError(){
    cout << "Triangle is not exist!" << endl;
    exit(0);
}

class Triangle{
private:
        double ax, ay;
        double bx, by;
        double cx, cy;
        vector<double> lengthSidesTriangle() {

            double side_ab = sqrt(pow((bx - ax), 2) + pow((by - ay), 2));
            double side_bc = sqrt(pow((cx - bx), 2) + pow((cy - by), 2));
            double side_ac = sqrt(pow((cx - ax), 2) + pow((cy - ay), 2));

            return {side_ab, side_bc, side_ac};
        }

        vector <double> anglesTriangle(){
            vector<double> sides = lengthSidesTriangle();

            double angle_cab = acos((pow(sides[0],2) + pow(sides[2],2) - pow(sides[1],2)) / (2 * sides[0] * sides[2])) * (180.0 / M_PI);
            double angle_abc = acos((pow(sides[0],2) + pow(sides[1],2) - pow(sides[2],2)) / (2 * sides[0] * sides[1])) * (180.0 / M_PI);
            double angle_bca = acos((pow(sides[1],2) + pow(sides[2],2) - pow(sides[0],2)) / (2 * sides[1] * sides[2])) * (180.0 / M_PI);

            return {angle_cab, angle_abc, angle_bca};
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
            vector<double> angles = anglesTriangle();

            cout << "AB: " << sides[0] << endl;
            cout << "BC: " << sides[1] << endl;
            cout << "AC: " << sides[2] << endl;

            cout << "CAB: " << angles[0] << endl;
            cout << "ABC: " << angles[1] << endl;
            cout << "BCA: " << angles[2] << endl;
        }
};


int main(){
    double x1, y1, x2, y2, x3, y3;
    cout << "Enter the coordinates of the points" << endl;
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
