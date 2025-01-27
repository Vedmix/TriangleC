
#include <stdio.h>
#include <string.h>
#include <math.h>



float side(float x1, float y1, float x2, float y2){
	return sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
}

float angle(float side1, float side2, float side3){
	return (acos((pow(side1,2) + pow(side2,2) - pow(side3,2)) / (2 * side1 * side2)) * (180.0 / M_PI));
	
}

float median(float side1, float side2, float side3) {
    return (1.0 / 2.0) * sqrt(2 * pow(side1, 2) + 2 * pow(side2, 2) - pow(side3, 2));
}

void equationYKB(float x1, float y1, float x2, float y2) {
    if (x2 == x1) {
        printf("x = %.2f\n", x1);
        return;
    } else if (y2 == y1) {
        printf("y = %.2f\n", y1);
        return;
    }

    float k = (y2 - y1) / (x2 - x1);
    float b = y1 - k * x1;

    if (b < 0.0) {
        printf("y = %.2fx + (%.2f)\n", k, b);
    } else if (b == 0.0) {
        printf("y = %.2fx\n", k);
    } else {
        printf("y = %.2fx + %.2f\n", k, b);
    }
}

void equationABC(float x1, float y1, float x2, float y2) {
	float a = y2 - y1;
	float b = x1 - x2;
	float c = x2 * y1 - x1 * y2;
	if (b == 0 && c == 0){
		printf("(%.2f)x = 0\n", a);
	} else if (a == 0 && c == 0){
		printf("(%.2f)y = 0\n", b);
	} else if (a == 0){
		printf("(%.2f)y + (%.2f) = 0\n", b, c);
	} else if (b == 0){
		printf("(%.2f)x + (%.2f) = 0\n", a, c);
	} else if (c == 0){
		printf("(%.2f)x + (%.2f)y = 0\n", a, b);
	} else{
		printf("(%.2f)x + (%.2f)y + (%.2f) = 0\n", a, b, c);
	}
	
	



}
int main(){
	float ax, ay, bx, by, cx, cy;
	float ab, bc, ac;
	float a_angle, b_angle, c_angle;
	float aa1, bb1, cc1;
	float p, s, h;
	
	printf("Enter the coordinates of the points.\n");
	printf("\n");
	printf("Point A: ");
	scanf("%f %f", &ax, &ay);
	printf("Point B: ");
	scanf("%f %f", &bx, &by);
	printf("Point C: ");
	scanf("%f %f", &cx, &cy);
	printf("\n");
	
	if ((ax == bx & ay == by) | (ax == cx & ay == cy) | (cx == bx & cy == by)){
		printf("Triangle is not exist!\n");
		return 0;
	}
	else{
	
	ab = side(ax, ay, bx, by);
	bc = side(bx, by, cx, cy);
	ac = side(ax, ay, cx, cy);
	
	a_angle = angle(ab, ac, bc);
	b_angle = angle(ab, bc, ac);
	c_angle = angle(bc, ac, ab);
	
	aa1 = median(ac, bc, ab); 
    bb1 = median(ab, bc, ac);
    cc1 = median(ab, ac, bc); 
	
	if (((ab + bc) > ac) && ((ac + bc) > ab) && ((ab + ac) > bc)){
	
		if (ab == bc == ac){
			printf("Type: Equilateral triangle\n");
		}
		
		else if ((a_angle == 90.0) || (b_angle == 90.0) || (c_angle == 90.0)){
		
			if ((ab != bc && bc == ac) || (ab == bc && bc != ac) || (ab == ac && ac != bc)){
				printf("Type: Rectangular triangle with two equal sides\n");
			}
			
			else{
				printf("Type: Rectangular triangle\n");
			}
		}
		
		else if ((a_angle < 90.0) && (b_angle < 90.0) && (c_angle < 90.0)){
		
			if ((ab != bc && bc == ac) || (ab == bc && bc != ac) || (ab == ac && ac != bc)){
				printf("Type: Acute triangle with two equal sides\n");
			}
			
			else{
				printf("Type: Acute triangle\n");
			}
		}
		
		else if ((a_angle > 90.0) || (b_angle > 90.0) || (c_angle > 90.0)){
		
			if ((ab != bc && bc == ac) || (ab == bc && bc != ac) || (ab == ac && ac != bc)){
				printf("Type: Obtuse triangle with two equal sides\n");
			}
			
			else{
				printf("Type: Obtuse triangle\n");
			}
		}	
	}
	
	else{
		printf("Triangle is not exist!\n");
		return 0;
	}
	p = ab + bc + ac;
	s = sqrt((p / 2) * ((p / 2) - ab) * ((p / 2) - bc) * ((p / 2) - ac));
	
	printf("\n");
	printf("Sides:   AB = %f \n", ab);
	printf("         BC = %f \n", bc);
	printf("         AC = %f \n", ac);
	printf("\n");
	printf("Angles:  BAC = %f \n", a_angle);
	printf("         ABC = %f \n", b_angle);
	printf("         BCA = %f \n", c_angle);
	printf("\n");
	printf("Medians: AA1 = %f \n", aa1);
	printf("         BB1 = %f \n", bb1);
	printf("         CC1 = %f \n", cc1);
	printf("\n");
	printf("Equations for edges: \n");
	printf("\n");
	printf("AB: ");
	equationYKB(ax, ay, bx, by);
	printf("BC: ");
	equationYKB(bx, by, cx, cy);
	printf("AC: ");
	equationYKB(ax, ay, cx, cy);
	printf("\n");
	printf("Equations for lines: \n");
	printf("\n");
	printf("AB: ");
	equationABC(ax, ay, bx, by);
	printf("BC: ");
	equationABC(bx, by, cx, cy);
	printf("AC: ");
	equationABC(ax, ay, cx, cy);	
	printf("\n");
	printf("Perimeter: %f \n", p);
	printf("\n");
	printf("Square:    %f \n", s);
	
	}
	
	char command[100];
	sprintf(command, "./win %f %f %f %f %f %f", ax, ay, bx, by, cx, cy); 
	system(command);
	return 0;
}
