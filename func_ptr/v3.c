#include<stdio.h>

float add(float, float);

int main(){
	float k=2.4;
	float j=4.8;

	float result = add(k,j);

	printf("%f\n", result);

}

float add(float a, float b){
	return a+b;
}
