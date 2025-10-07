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
int deleteFromEnd();

int main(){
	int ele,pos;
	int choice;
	int ret;

	while(1)
	{
		printf("Enter 1->insert 2->display 3->exit 4->insertAtBeg ");
		printf("4->insertAtBeg 5->insertAtPos 6->deleteFromEnd\n");
		printf("7->deleteFromBeg");
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

			case 6:
				ret = deleteFromEnd();
				printf("node with val=[%d] got delted\n",ret);
				break;

			case 7:
				ret = deleteFromBeg();
				printf("node with val=[%d]got deleted\n",ret);
				break;

			case 3:
				exit(0);
		}
	}
}

int deleteFromEnd(){
	struct node *t1,*t2;
	t1=head;
	t2=NULL;

	while(t1->next != NULL)
	{
		//task1/2
		t2=t1;
		t1=t1->next;
	}
	int ret=t1->data;
	//task2/2
	free(t1);
	t2->next=NULL;

	return ret;
}

int deleteFromBeg(){
	struct node* t1;
	t1=head;

	int ret=t1->data;

	//
	head=t1->next;
	free(t1);

	return ret;
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
	//handle special case
	if(pos==1)
	{
		insertAtBeg(ele);
		return; //important
	}

	//temp is temporary node-pointer
	//temp have 12 bytes memory
	struct node * temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data = ele;
	temp->next = NULL;

	//making t6 pointing at proper node
	struct node* t6;
	t6=head;
	int i=1;
	while(++i<pos)
	{
		t6=t6->next;
	}
	
	// sequence is imp; A then B	
	temp->next = t6->next;
	t6->next = temp;
}


	
