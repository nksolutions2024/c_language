#include<stdio.h>
#include<stdlib.h>

struct node{
	int data ;
	struct node * next;
};


void insertAtEnd(struct node**, int);
void display(struct node *);

int main(){
	struct node* head= NULL;
//	*head = NULL;
	int ele;
	int choice;

	while(1)
	{
		printf("Enter 1->insert 2->display 3->exit");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter ele-insert-end: ");
				scanf("%d",&ele);
				insertAtEnd(&head,ele);
				break;

			case 2: 
				printf("linked_list\n");
				display(head);
				break;

			case 3:
				exit(0);
		}
	}
}


void insertAtEnd(struct node **ptr, int ele){
	struct node * temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = ele;
	temp->next = NULL;

	struct node* t1;
	t1 = *ptr;
	
	if(*ptr==NULL)
	{
		*ptr = temp;
		return;
	}

	while(t1->next != NULL)
	{
		t1=t1->next;
	}
	
	//finally , making connection
	t1->next = temp;
}

void display(struct node*p){
	//p
	while(p != NULL)
	{
		printf("-->[%d]", p->data);
		p = p->next;
	}
}



	
