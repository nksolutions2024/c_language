#include<stdio.h>
#include<stdlib.h>

int arr[5]= {-99,-99,-99,-99,-99};
#include "myheader.h" //include the header file

void revDisplay();
		      
int main(){
	int u_index,u_value;
	int choice;

	while(1)
	{
		printf("Enter 1->insert 2->display 3->exit 4->delByIndex ");
	      	printf("5->deleteByEle 8->reverse_display : ");
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

			case 8:
				revDisplay();
				break;

			case 3:
				exit(0);
		}
	}

}

void revDisplay(){
	for(int i=4; i>=0; i--)
	{
		printf("%d \t", arr[i]);
	}
}
