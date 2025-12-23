#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

void arr_init(int* arr);
void display();
void enqueue(int* arr, int*front, int*rear, int ele);


int main(){
	int choice;

	while(1)
	{
		printf("Enter 1->insert 2->display 3->exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("insert function pending\n");
				break;

			case 2:
				printf("queue is \n");
				display();
				break;

			case 3:
				exit(1);
		}



	}
}

void arr_init(int* arr){
	for(int i=0; i<SIZE; i++)
	{
		arr[i]=-99;
	}
}

void display(int* arr){
	for(int i=0; i<SIZE; i++)
	{
		printf("[%d]-", arr[i]);
	}
	printf("\b\b||||||||\n");
}

