#include<stdio.h>
#include<stdlib.h>

int main(){
	int choice;
	printf("outside while\n");


	while(1)
	{
		printf("Enter 1-> 9->exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("hhello, you typed one\n");
				break;

			case 9:
				exit(0);
		}
	}

}

