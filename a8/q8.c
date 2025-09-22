#include<stdio.h>

struct circle{
	float r;
	float area;
}listofcircle[10];

int c_area_cal(float m);

int main(){
	float r1=14, r2=55;
	float temp;
	int i;
	
	for(i=0; i<10; i++)
	{	
		float temp1;
		printf("\nEnter the radius of circle--%d : ", i+1);
		scanf("%f",&temp1);
		listofcircle[i].r = temp1;
	}
		
	for(i=0; i<10; i++)
	{
		listofcircle[i].area = c_area_cal(listofcircle[i].r);
	}

//	temp = c_area_cal(r1);
	for(i=0; i<10; i++)
	{
		printf("\n %lf \n", listofcircle[i].area);
	}

	return 0;
}

int c_area_cal(float m){
	float area_c;
	area_c = 3.14*m*m;
	return area_c;
}

