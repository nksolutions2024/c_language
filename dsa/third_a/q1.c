#include<stdio.h>

int arr[5]={10,20,40,50,30};
void display();

int main(){
	//bubble sort

	display();

}

void display(){
	for(int i=0; i<5; i++)
	{
		printf("%d-",arr[i]);
	}
	printf("\n");
}
