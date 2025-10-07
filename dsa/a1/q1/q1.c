#include<stdio.h>
#include<stdlib.h>

int arr[5]={10,20,10,40,50};
#include "myheader.h" //include the header file

struct clist{
	int ele;
	int ecount;
}arrStruct[5];

void duplicate();
		      
int main(){
	int u_index, u_value, pos ;
	int choice;

	while(1)
	{
		printf("Enter 1->insert 2->display 3->exit 4->delByIndex ");
	      	printf("5->deleteByEle 8->reverse_display 9->search 10->duplicate : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 10:
				duplicate();
				break;

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
				printf("Enter index for deleting: ");
				scanf("%d", &u_index);
				deleteByIndex(u_index);
				break;

			case 5:
				printf("Enter value to be deleted: ");
				scanf("%d",&u_value);
				deleteByEle(u_value);
				break;

			case 8:
				revDisplay();
				break;

			case 9:
				printf("Enter element to be searched: ");
				scanf("%d", &u_value);
				pos = search(u_value);
				printf("Element at index:%d",pos);
				//case2 not found ; pos = -1
				break;

			case 3:
				exit(0);
		}
	}

}

void duplicate(){
	for(int i;i<5;i++)
	{
		arr[i];
		arrStruct[i].ecount=0;

		for(int j=0;i<n-i-1;i++)
		{
			if(arr[i]==arr[j])
			{
				arrStruct[i].ecount++;
			}
		}
				
	}
	//display array of struct
}
