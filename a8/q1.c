#include<stdio.h>

struct addition {
	int num1;
	int num2;
	int sum;
};

int main(){
	struct addition var;

	scanf("%d", &var.num1);
	scanf("%d", &var.num2);
	var.sum = var.num1 + var.num2;
	printf("\n %d \n", var.sum);

	return 0;
}
