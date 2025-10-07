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
	int ele,pos;
	int choice;

	while(1)
	{
		printf("Enter 1->insert 2->display 3->exit 4->insertAtBeg ");
		printf("4->insertAtBeg 5->insertAtPos\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter ele-insert-end: ");
				scanf("%d",&ele);
				insertAtEnd(ele);
				break;

			case 2: 
				printf("linked_list\n");
				display();
				break;

			case 4:
				printf("enter ele-begin: ");
				scanf("%d",&ele);
				insertAtBeg(ele);
				break;

			case 5:
				printf("enter ele and pos");
				scanf("%d %d", &ele, &pos);
				insertAtPos(ele, pos);
				break;

			case 3:
				exit(0);
		}
	}
}

void insertAtEnd(int ele){
	//traversing pointer t1;initized to head 
	struct node * t1;
	t1=head;
	
	//temp is temporary node-pointer 
	struct node * temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data = ele;
	temp->next =NULL;

	if(head==NULL)
	{
		//ll does not exist
		head=temp;
		return; //important1
			//leave the function from here directly
	}

	//made mistake of ELSE BLOCK
	//traverse to last node
	while(t1->next != NULL)
	{
		t1=t1->next; //jumped
	}
	
	//last node's link part is changed
	t1->next = temp ;

}

void display(){
	struct node * t2;
	t2=head;

	while(t2 != NULL) //caution:- condition check
	{
		printf("-->[%d]", t2->data);
		t2 = t2->next;
	}
	printf("\n");
}

void insertAtBeg(int ele){
	//temp is temporary node-pointer
	//temp have 12 bytes
	struct node * temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data = ele;
	temp->next = NULL;

	//scenario ll exits
	temp->next = head;	//sequence-A
	head=temp;		//sequence-B
}

void insertAtPos(int ele, int pos){
	//temp is temporary node-pointer
	//temp have 12 bytes memory
	struct node * temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data = ele;
	temp->next = NULL;

/*
	//wrong code below
	//reach to last node
	struct node* t5;
	t5=head;
	while(t5->next != NULL)
	{	
		t5=t5->next;
	}

	//AA
	temp->next = t5;
*/
}


	
