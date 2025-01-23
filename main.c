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

int main(){
	float ax, ay, bx, by, cx, cy;
	float ab, bc, ac;
	float a_angle, b_angle, c_angle;
	float aa1, bb1, cc1;
	float p, s;
	
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
    cc1 = median(ab, ac, bc); // медиана к стороне BC
	
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
	printf("Sides:   AB = %f cm\n", ab);
	printf("         BC = %f cm\n", bc);
	printf("         AC = %f cm\n", ac);
	printf("\n");
	printf("Angles:  BAC = %f °\n", a_angle);
	printf("         ABC = %f °\n", b_angle);
	printf("         BCA = %f °\n", c_angle);
	printf("\n");
	printf("Medians: AA1 = %f cm\n", aa1);
	printf("         BB1 = %f cm\n", bb1);
	printf("         CC1 = %f cm\n", cc1);
	printf("\n");
	printf("Perimeter: %f cm\n", p);
	printf("\n");
	printf("Square:    %f cm\n", s);
	
	}
	
	return 0;
}