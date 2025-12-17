#include<stdio.h>
#include<stdlib.h>

void insertAtEnd(int **, int);
void display();

struct node{
	int data;
	struct node * next;
};

int main(){
	struct node * head;
	head = NULL;
	int ele;
	int choice;
	printf("Enter 1->insertAtEnd 2->display 3->exit\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			printf("Enter the element to be inserted:\n");
			scanf("%d", &ele);
			insertAtEnd( ,ele);
			break;

		case 2:
			display();
			break;

		case 3: 
			exit(0);
	}

}

void insertAtEnd(struct node , int ele ){
	struct node * temp = (struct node *)malloc(sizeof(struct node));

	if()

}
