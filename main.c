#include <stdio.h>
#include <string.h>
#include <math.h>



float side(float x1, float y1, float x2, float y2){
	return sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
}

float angle(float side1, float side2, float side3){
	return (acos((pow(side1,2) + pow(side2,2) -pow(side3,2)) / (2 * side1 * side2)) * (180.0 / M_PI));
	
}

int main(){
	float ax, ay, bx, by, cx, cy;
	float ab, bc, ac;
	float a_angle, b_angle, c_angle;
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
	
	printf("Sides: %f %f %f \n", ab, bc, ac);
	printf("Angles: %f %f %f \n", a_angle, b_angle , c_angle);
	printf("Perimeter: %f\n", p);
	printf("Square: %f\n", s);
	
	}
	
	return 0;
}