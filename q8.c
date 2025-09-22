#include<stdio.h>

struct circle{
	float r;
	float area;
}arr[10];

int c_area_cal(float m);

int main(){
	float r1=14, r2=55;
	float temp;

	temp = c_area_cal(r1);
	printf("\n %d \n", temp);



	return 0;
}

int c_area_cal(float m){
	float area_c;
	area_c = 3.14*m*m;
	return area_c;
}

