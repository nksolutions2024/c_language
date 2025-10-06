#include<stdio.h>
#include<stdlib.h>

int arr[5]= {-99,-99,-99,-99,-99};

void insertAtIndex(int n,int index);
void display();
void deleteByIndex(int index);
void deleteByEle(int ele);
int arrMin();
int arrMax();

int main(){
	int u_index,u_value;
	int choice;

	while(1)
	{
		printf("Enter the 1->insert 2->display 3->exit 4->deleteByIndex 5->deleteByEle 6->arrMin 7->arrMax: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter index where to insert : ");
				scanf("%d", &u_index);
				printf("Enter value of element : ");
				scanf("%d", &u_value);
				insertAtIndex(u_value, u_index);
				break;
			case 2: 
				display();
				break;
			case 4:
				printf("Enter index for deleting");
				scanf("%d", &u_index);
				deleteByIndex(u_index);
				break;
			case 5:
				printf("Enter value to be deleted");
				scanf("%d",&u_value);
				deleteByEle(u_value);
				break;
			case 6:
				printf("%d\n", arr[arrMin()]);
			case 3:
				exit(0);
		}
	}

}

void insertAtIndex(int n,int index){

	// index above 4 ,warning

	if(arr[index] == -99)
	{
		arr[index]=n;
	}
	else
	{
		printf("already element there\n");
	}
}

void display(){
	int i;
	for(i=0; i<5; i++)
	{
		printf("%d\n",arr[i]);
	}
}

void deleteByIndex(int index){
	if (arr[index] != -99)
	{
		printf("Deleted element was %d\n",arr[index]);
		arr[index] = -99;
	}
	else
	{
		printf("Already empty\n");
	}

}

void deleteByEle(int ele)
{
	for(int i=0; i<5; i++)
	{
		if(arr[i] == ele)
		{
			arr[i]=-99;
		}
		//consider case of not found
	}
}

int arrMin(){
	//assume arr[0] is Min 
	//assuming arr[0] is not -99
	int minIndex = 0;
	for(int i; i<5; i++)
	{
		if(arr[i]<arr[minIndex] && arr[i]!=-99)
		{
			minIndex=i;
		}
	}
	return minIndex;
}
