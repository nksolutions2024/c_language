#include<stdio.h>
#include<stdlib.h>

int main(){
	int user_variable=5;

	void *v_ptr;
	v_ptr = malloc(sizeof(int)*user_variable);
	int* special_ptr;
	special_ptr = (int*)v_ptr;

	//arr[0]
	*special_ptr = 10;
	*(special_ptr+1) = 20;
	*(special_ptr+2) = 30;

	for(int i=0; i<=2;i++)
	{
		printf("\n%d\n", *(special_ptr+i) );
	}
}
