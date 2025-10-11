#include<stdio.h>

int arr[6]={30,20,60,10,90,80};
void display();
void bubbleSort();
void swap(int*,int*);
void selectionSort();

int main(){
	int var1=10,var2=20;
	printf("before\n");
	display();
	
	printf("after\n");
	//bubbleSort();
	selectionSort();
	display();

}

void selectionSort(){
	int min_idx;
	min_idx = 0;
	for(int i=0; i<6-1; i++) //upto second last element
	{
		min_idx = i;
		for(int j=i+1; j<6; j++)
		{
			if( arr[min_idx]>arr[j] )
			{
				min_idx=j;
			}
			display();
		}
		swap(&arr[i],&arr[min_idx]);
		printf("-------------\n");
		display();
		printf("-------------\n\n");
	}
}

void swap(int* a, int* b){
	int temp;

	temp=*a;
	*a=*b;
	*b=temp;
}

void bubbleSort(){
	for(int i=0; i<6; i++){
		for(int j=0;j<6-i-1;j++){
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}

}

void display(){
	for(int i=0; i<6; i++)
	{
		printf("%d-",arr[i]);
	}
	printf("\n");
}
