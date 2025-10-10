#include<stdio.h>

int arr[6]={10,20,40,50,30};
void display();
void bubbleSort();
void swap(int*,int*);

int main(){
	//bubble sort
	printf("before\n");
	display();
	printf("after\n");
	display();

}

void swap(int* a, int* b){
	int temp;

	temp=*a;
	*a=*b;
	*b=temp;
}

void bubbleSort(){
	for(int i=0; i<6; i++){
		for(int j=i+1;j<6;j++){
			if(arr[i]>arr[i+1])
			{
				swap(&arr[i],&arr[i+1]);
			}
		}
	}

}
void display(){
	for(int i=0; i<5; i++)
	{
		printf("%d-",arr[i]);
	}
	printf("\n");
}
