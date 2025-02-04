#include <stdio.h>
#include <string.h>
#include <math.h>



double side(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
}

double angle(double side1, double side2, double side3)
{
    return (acos((pow(side1,2) + pow(side2,2) - pow(side3,2)) / (2 * side1 * side2)) * (180.0 / M_PI));

}

double median(double side1, double side2, double side3)
{
    return (1.0 / 2.0) * sqrt(2 * pow(side1, 2) + 2 * pow(side2, 2) - pow(side3, 2));
}

void equationYKB(double x1, double y1, double x2, double y2)
{
    if (x2 == x1) {
        printf("x = %.2lf\n", x1);
        return;
    } else if (y2 == y1) {
        printf("y = %.2lf\n", y1);
        return;
    }

    double k = (y2 - y1) / (x2 - x1);
    double b = y1 - k * x1;

    if (b < 0.0) {
        printf("y = %.2lfx + (%.2lf)\n", k, b);
    } else if (b == 0.0) {
        printf("y = %.2lfx\n", k);
    } else {
        printf("y = %.2lfx + %.2lf\n", k, b);
    }
}

void equationABC(double x1, double y1, double x2, double y2)
{
    double a = y2 - y1;
    double b = x1 - x2;
    double c = x2 * y1 - x1 * y2;
    if (b == 0 && c == 0) {
        printf("(%.2lf)x = 0\n", a);
    } else if (a == 0 && c == 0) {
        printf("(%.2lf)y = 0\n", b);
    } else if (a == 0) {
        printf("(%.2lf)y + (%.2lf) = 0\n", b, c);
    } else if (b == 0) {
        printf("(%.2lf)x + (%.2lf) = 0\n", a, c);
    } else if (c == 0) {
        printf("(%.2lf)x + (%.2lf)y = 0\n", a, b);
    } else {
        printf("(%.2lf)x + (%.2lf)y + (%.2lf) = 0\n", a, b, c);
    }





}
int main()
{
    double ax, ay, bx, by, cx, cy;
    double ab, bc, ac;
    double a_angle, b_angle, c_angle;
    double aa1, bb1, cc1;
    double p, s, h;

    printf("Enter the coordinates of the points.\n");
    printf("\n");
    printf("Point A: ");
    scanf("%lf %lf", &ax, &ay);
    printf("Point B: ");
    scanf("%lf %lf", &bx, &by);
    printf("Point C: ");
    scanf("%lf %lf", &cx, &cy);
    printf("\n");

    if ((ax == bx & ay == by) | (ax == cx & ay == cy) | (cx == bx & cy == by)) {
        printf("Triangle is not exist!\n");
        return 0;
    } else {

        ab = side(ax, ay, bx, by);
        bc = side(bx, by, cx, cy);
        ac = side(ax, ay, cx, cy);

        a_angle = angle(ab, ac, bc);
        b_angle = angle(ab, bc, ac);
        c_angle = angle(bc, ac, ab);

        aa1 = median(ac, bc, ab);
        bb1 = median(ab, bc, ac);
        cc1 = median(ab, ac, bc);

        if (((ab + bc) > ac) && ((ac + bc) > ab) && ((ab + ac) > bc)) {

            if (ab == bc == ac) {
                printf("Type: Equilateral triangle\n");
            }

            else if ((a_angle == 90.0) || (b_angle == 90.0) || (c_angle == 90.0)) {

                if ((ab != bc && bc == ac) || (ab == bc && bc != ac) || (ab == ac && ac != bc)) {
                    printf("Type: Rectangular triangle with two equal sides\n");
                }

                else {
                    printf("Type: Rectangular triangle\n");
                }
            }

            else if ((a_angle < 90.0) && (b_angle < 90.0) && (c_angle < 90.0)) {

                if ((ab != bc && bc == ac) || (ab == bc && bc != ac) || (ab == ac && ac != bc)) {
                    printf("Type: Acute triangle with two equal sides\n");
                }

                else {
                    printf("Type: Acute triangle\n");
                }
            }

            else if ((a_angle > 90.0) || (b_angle > 90.0) || (c_angle > 90.0)) {

                if ((ab != bc && bc == ac) || (ab == bc && bc != ac) || (ab == ac && ac != bc)) {
                    printf("Type: Obtuse triangle with two equal sides\n");
                }

                else {
                    printf("Type: Obtuse triangle\n");
                }
            }
        }

        else {
            printf("Triangle is not exist!\n");
            return 0;
        }
        p = ab + bc + ac;
        s = sqrt((p / 2) * ((p / 2) - ab) * ((p / 2) - bc) * ((p / 2) - ac));

        printf("\n");
        printf("Sides:\n");
        printf("         AB = %lf \n", ab);
        printf("         BC = %lf \n", bc);
        printf("         AC = %lf \n", ac);
        printf("\n");
        printf("Angles:\n");
        printf("         BAC = %lf \n", a_angle);
        printf("         ABC = %lf \n", b_angle);
        printf("         BCA = %lf \n", c_angle);
        printf("\n");
        printf("Medians:\n");
        printf("         AA1 = %lf \n", aa1);
        printf("         BB1 = %lf \n", bb1);
        printf("         CC1 = %lf \n", cc1);
        printf("\n");
        printf("Equations for edges: \n");
        printf("\n");
        printf("         AB: ");
        equationYKB(ax, ay, bx, by);
        printf("         BC: ");
        equationYKB(bx, by, cx, cy);
        printf("         AC: ");
        equationYKB(ax, ay, cx, cy);
        printf("\n");
        printf("Equations for lines: \n");
        printf("\n");
        printf("         AB: ");
        equationABC(ax, ay, bx, by);
        printf("         BC: ");
        equationABC(bx, by, cx, cy);
        printf("         AC: ");
        equationABC(ax, ay, cx, cy);
        printf("\n");
        printf("Perimeter: %lf \n", p);
        printf("\n");
        printf("Square:    %lf \n", s);

    }

    char command[100];
    sprintf(command, "./win %lf %lf %lf %lf %lf %lf", ax, ay, bx, by, cx, cy);
    system(command);
    return 0;
}













