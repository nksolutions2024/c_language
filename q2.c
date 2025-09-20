#include<stdio.h>

void main(){
	int num;
	num = 45;
	
	register int *num1 ;

	printf("\n %ld \n", sizeof(num1));
	printf("\n %d \n", num1);

	printf("\n %ls \n", num1);
}
