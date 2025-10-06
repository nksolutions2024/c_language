#include<stdio.h>
#include<stdlib.h>

int arr[5]= {-99,-99,-99,-99,-99};

void insertAtIndex(int n,int index);
void display();

int main(){
	int u_index,u_value;
	int choice;

	while(1)
	{
		printf("Enter the 1->insert 2->display");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("inserting");
				break;
			case 2: 
				display();
				break;
			case 3:
				exit(0);
		}
	}


/*
	printf("Enter index where to insert : ");
	scanf("%d", &u_index);
	printf("Enter value of element : ");
	scanf("%d", &u_value);

//	insertAtIndex(20,1);
	insertAtIndex(u_value,u_index);
//	display();
*/
}

void insertAtIndex(int n,int index){

	if(arr[index != -99])
	{
		arr[index]=n;
	}
	else
	{
		printf("already element there");
	}
}

void display(){
	int i;

	for(i=0; i<5; i++)
	{
		printf("%d\n",arr[i]);
	}
}
