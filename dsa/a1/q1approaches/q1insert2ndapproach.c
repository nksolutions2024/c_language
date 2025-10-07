#include<stdio.h>
#include<stdlib.h>

int arr[5]={-99,-99,-99,-99,-99};
#include "myheader1.h" //include the header file

void i_approach2nd(int index, int value);
		      
int main(){
	int u_index, u_value ;
	int choice;

	while(1)
	{
		printf("Enter 4->insert 2->display 3->exit ");
		scanf("%d",&choice);
		switch(choice)
		{
/*
			case 1:
				printf("Enter index where to insert : ");
				scanf("%d", &u_index);
				printf("Enter value of element : ");
				scanf("%d", &u_value);
				insertAtIndex(u_value, u_index);
				break;
*/
			case 4:
				printf("Enter index where to insert : ");
				scanf("%d", &u_index);
				printf("Enter value of element : ");
				scanf("%d", &u_value);
				i_approach2nd(u_index, u_value);
				break;

			case 2: 
				display();
				break;


			case 3:
				exit(0);
		}
	}

}

void i_approach2nd(int index , int value ){
	if(arr[index]==-99)
	{
		arr[index]=value;
	}
	else
	{
		//swift to right
		if(arr[4]==-99)// last slot is empty
		{
			//half part free slot ckecking
			for(int i=4; i>index; i--)
			{
				//element[3] copied to element[4]
				arr[i] = arr[i-1];
			}
		}
		//finally assigned
		arr[index]=value;
	}
}
/*
 desd@desd-OptiPlex-5050:~/Documents/embc/c_language/dsa/a1/q1approaches$ ./a.out
Enter 4->insert 2->display 3->exit 2
-99
-99
-99
-99
-99
Enter 4->insert 2->display 3->exit 4
Enter index where to insert : 1
Enter value of element : 11
Enter 4->insert 2->display 3->exit 2
-99
11
-99
-99
-99
Enter 4->insert 2->display 3->exit 4
Enter index where to insert : 2
Enter value of element : 22
Enter 4->insert 2->display 3->exit 4
Enter index where to insert : 3 
Enter value of element : 33
Enter 4->insert 2->display 3->exit 2
-99
11
22
33
-99
Enter 4->insert 2->display 3->exit 4
Enter index where to insert : 1
Enter value of element : 84
Enter 4->insert 2->display 3->exit 2
-99
84
11
22
33
Enter 4->insert 2->display 3->exit 3
desd@desd-OptiPlex-5050:~/Documents/embc/c_language/dsa/a1/q1approaches$ 
 * /
