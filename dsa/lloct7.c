#include<stdio.h>
#include<stdlib.h>

struct node{
	int data ;
	struct node * next;
};

struct node* head = NULL; //pointer to first node

void insertAtEnd(int ele);
void display();

int main(){
	int choice,ele;

	while(1)
	{
		printf("Enter 1->insert 2->display 3->exit \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter ele to be insert at end: ");
				scanf("%d",&ele);
				insertAtEnd(ele);
				break;

			case 2:
				display();
				break;

			case 3:
				exit(0);
		}
	}
}

void insertAtEnd(int ele){
	struct node * t1;
	t1=head;
	struct node * temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data = ele;
	temp->next =NULL;

	//ll does not exist (IF BLOCK)
	if(head==NULL)
	{
		head=temp;
		return; //important1
	}

	//made mistake of ELSE BLOCK
		//traverse to last node
		while(t1->next != NULL)
		{
			t1=t1->next; //jumped
		}
	
	//last node link is changed
	t1->next = temp ;

}

void display(){
	struct node * t2;
	t2=head;

	while(t2 != NULL)
	{
		printf("-->[%d]", t2->data);
		t2 = t2->next;
	}
}
