#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

void arr_init(int* arr);
void display();
void enqueue(int* arr, int*front, int*rear, int ele);
int dequeue(int* a, int* f, int* r);


int main(){
	int arr[SIZE], arr1[5]={2,2,2,2,2};
	int choice,ele;
	arr_init(arr);
	int front=-1;//not int* front
	int rear=-1;
	int ret;

	while(1)
	{
		printf("Enter 1->insert 2->display 3->exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter ele: ");
				scanf("%d",&ele);
				enqueue(arr,&front,&rear,ele);
				break;

			case 2:
				printf("queue is \n");
				display(arr);
				break;
			
			case 4:
				ret = dequeue(arr,&front,&rear);
				printf("dequeue item = %d\n", ret);
				break;

			case 3:
				exit(1);

		}



	}
}

int dequeue(int* a, int* f, int* r){
	int temp;
	if(*f==-1)
	{
		printf("queue is empty\n");
		return -99;
	}
	
	temp = a[*f];
	a[*f] = -99;

	if(*f == *r)
	{
		*f=*r=-1;
	}
	else
	{
		(*f)++;
	}
	return temp;
	
}

void enqueue(int* a,int* f,int* r,int ele){
	if(*r==SIZE-1)
	{
		printf("queue is full\n");
		return;
	}
	(*r)++;
	a[*r]=ele;
	if(*f==-1)
	{
		*f=0;
	}

}

void arr_init(int* arrvar){
	for(int i=0; i<SIZE; i++)
	{
		arrvar[i]=-99;
	}
}

void display(int* a){
	for(int i=0; i<SIZE; i++)
	{
		printf("[%d]-", a[i]);
	}
	printf("\b||||||||\n");
}

