#include <stdio.h>
#include <string.h>
#include <math.h>



float side(float x1, float y1, float x2, float y2){
	return sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
}

double angle(float side1, float side2, float side3){
	return (acos((pow(side1,2) + pow(side2,2) -pow(side3,2)) / (2 * side1 * side2)) * (180.0 / M_PI));
	
}

int main(){
	float ax, ay, bx, by, cx, cy;
	float ab, bc, ac;
	float a_angle, b_angle, c_angle;
	printf("Enter the coordinates of the points.\n");
	printf("Point A: ");
	scanf("%f %f", &ax, &ay);
	printf("Point B: ");
	scanf("%f %f", &bx, &by);
	printf("Point C: ");
	scanf("%f %f", &cx, &cy);
	
	if ((ax == bx & ay == by) | (ax == cx & ay == cy) | (cx == bx & cy == by)){
		printf("Triangle is not exist!");
		return 0;
	}
	else{
	ab = side(ax, ay, bx, by);
	bc = side(bx, by, cx, cy);
	ac = side(ax, ay, cx, cy);
	
	a_angle = angle(ab, ac, bc);
	b_angle = angle(ab, bc, ac);
	c_angle = angle(bc, ac, ab);
	
	
	
	printf("Sides: %f %f %f \n", ab, bc, ac);
	printf("Angles: %lf %lf %lf \n", a_angle, b_angle, c_angle);
	}
	
	return 0;
}