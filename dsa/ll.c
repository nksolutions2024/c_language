#include<stdio.h>
#include<stdlib.h>

struct node{
	int data ;
	struct node * next;
};

struct node* head = NULL; //pointer to first node

void insertAtEnd(int ele);
void display();
void insertAtBeg(int ele);
void insertAtPos(int ele, int pos);

int main(){
	int choice,ele,pos;

	while(1)
	{
		printf("Enter 1->insert 2->display 3->exit 4->insertAtBeg ");
		printf("4->insertAtBeg 5->insertAtPos\n");
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

			case 4:
				printf("enter ele: ");
				scanf("%d",&ele);
				insertAtBeg(ele);
				break;

			case 5:
				printf("eneter ele and pos");
				scanf("%d %d", &ele, &pos);
				insertAtPos(ele, pos);
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
	printf("\n");
}

void insertAtBeg(int ele){
	struct node * temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data = ele;
	temp->next = NULL;

	//scenario ll exits
//	struct node * t4;
//	t4=head;
	temp->next = head;//A
	head=temp;
}






























void insertAtPos(int ele, int pos){
	struct node * temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data = ele;
	temp->next = NULL;

	//reach to last node
	struct node* t5;
	t5=head;
	while(t5->next != NULL)
	{	
		t5=t5->next;
	}

	//AA
	temp->next = t5;




	
