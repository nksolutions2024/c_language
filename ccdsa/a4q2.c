#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

void push(int*, int*, int);
int pop(int*, int*);
void displayStack(int*);
void init_stack(int*);

int main(){
	int arr[SIZE];
	int top;
	top = -1;
	int choice,ele,ret;

	init_stack(arr);

	while(1)
	{
		printf("enter 1->push 2->pop \n"); 
		printf("4->display_stack 7->exit \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter ele\n");
				scanf("%d",&ele);
				push(arr,&top,ele);
				break;

			case 2:
				ret = pop(arr, &top);
				printf("popped item = %d\n", ret);
				break;

			case 4:
				printf("stack status\n");
				printf("with top=[%d]\n", top);
				displayStack(arr);
				break;

			case 7:
				exit(1);
		}
	}
		
}

void init_stack(int *a){
	for(int i=0; i<SIZE; i++)
	{
		a[i]=-99;
	}
}

void displayStack(int* a){
	for(int i=0; i<SIZE; i++)
	{
		printf("[%d]\n",a[i]);
	}
	printf("\n----\n");
	
}

void push(int *a, int *t, int ele){
	if(*t++==SIZE-1)
	{
		printf("stack is full\n");
	}
	(*t)++;
	a[*t]=ele;
}

int pop(int* a, int *t){
	if(*t==-1)
	{
		printf("stack is empty\n");
		return -98;
	}
	int temp;
	temp = a[*t];
	a[*t] = -99;
	(*t)--;
	return temp;
}


