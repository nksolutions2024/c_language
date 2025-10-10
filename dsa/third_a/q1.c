#include<stdio.h>

int arr[6]={30,20,60,10,90,80};
void display();
void bubbleSort();
void swap(int*,int*);

int main(){
	int var1=10,var2=20;
	//bubble sort
	printf("before\n");
	printf("%d %d\n",var1,var2);
	display();
	
	printf("after\n");
	bubbleSort();
	swap(&var1,&var2);
	printf("%d %d\n",var1,var2);
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
		for(int j=i+1;j<6-i-1;j++){
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
