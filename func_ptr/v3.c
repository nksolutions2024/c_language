#include<stdio.h>

float add(float, float);

struct operations{
	float (*addition)(float, float);
	float (*subtraction)(float, float);
};

int main(){
	float k=2.4;
	float j=8.8;

	struct operations var_of_struct;

	var_of_struct.addition = add;

	float result;
	resullt	= var_of_struct.addition(k,j);

//	float result = add(k,j);

	printf("%f\n", result);

}

float add(float a, float b){
	return a+b;
}
