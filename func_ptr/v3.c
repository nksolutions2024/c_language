#include<stdio.h>
#include<stdlib.h>

float add(void *);

struct operations{
	float (*addition)(void*);
	float (*subtraction)(float, float);
};

struct input{
	float num1;
	float num2;
};

int main(){
	float k=2.4;
	float j=8.8;

	struct operations var_of_struct;
	struct input *firstinput;
	firstinput = malloc(sizeof(struct input));
	firstinput -> num1 = 4.16;
	firstinput -> num2 = 4.8;

	var_of_struct.addition = add;

	float result;
	result	= var_of_struct.addition(firstinput);

//	float result = add(k,j);

	printf("%f\n", result);
	free(firstinput);

}

float add(void *struct_ptr){
	struct input *temp;
	temp = (struct input*)struct_ptr;
	printf("num1 num2 -- %f %f\n", temp->num1, temp->num2);
	return (temp->num1 + temp->num2);
}
