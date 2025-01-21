#include <stdio.h>
#include <string.h>
#include <math.h>



float side(float x1, float x2, float y1, float y2){
	return sqrt(pow((x2-x1),2) + pow((y2-y1),2));
}

int main(){
	float ax, ay, bx, by, cx, cy, ab, bc, ac;
	printf("Enter the coordinates of the points.\n");
	printf("Point A: ");
	scanf("%f %f", &ax, &ay);
	printf("Point B: ");
	scanf("%f %f", &bx, &by);
	printf("Point C: ");
	scanf("%f %f", &cx, &cy);
	
	ab=side(ax, ay, bx, by);
	bc=side(cx, cy, bx, by);
	ac=side(ax, ay, cx, cy);
	
	printf("Sides %f %f %f", ab, bc, ac);
	
	
	return 0;
}