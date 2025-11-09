#include<stdio.h>

void areaperi(int, float*, float*);

int main(){
	int radius;
	float area, perimeter;
	printf("Enter radius of a circle");
	scanf("%d", &radius);
	areaperi(radius, &area, &perimeter);
	printf("Area = %f\n", area);
	printf("Perimeter = %f\n", area);


