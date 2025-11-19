#include<stdio.h>
#include<stdlib.h>

struct node{
	int data ;
	struct node * next;
};

void insert_at_end(struct node **, int);
void display(struct node *);
void delete_at_end(struct node **);

int main(){
	struct node * head;
	head = NULL;

	int ele;
	int choice;
	while(1)
	{
		printf("Enter 1->insert 2->display 3->exit\n");
		printf("4->delete_at_end\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter ele-insert-end: ");
				scanf("%d",&ele);
				insert_at_end(&head,ele);
				break;

			case 2: 
				printf("linked_list\n");
				printf("%p\n", head);
				display(head);
				break;

			case 4:
				delete_at_end(&head);
				break;

			case 3:
				exit(0);
		}

	}
}

void delete_at_end(struct node ** p){
	struct node * t2, *t4;
	t2 = *p; 
	//one node case, remaining

	while(t2->next != NULL)
	{
		t4=t2;
		t2=t2->next;
	}

	//free last node
	free(t2);
	//last-but-one(modify next)
	t4->next = NULL;
	printf("deleted last-node sucessfully\n");
}

void insert_at_end(struct node** p, int ele){
	struct node * temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = ele;
	temp->next = NULL;

	struct node* t1;
	t1 = *p;
	
	if(*p==NULL)
	{
		*p = temp;
		return;
	}

	while(t1->next != NULL)
	{
		t1=t1->next;
	}
	
	//finally , making connection
	t1->next = temp;
}

void display(struct node*g){
	struct node *address_temp;
	address_temp = g;
	//g
	while(g != NULL)
	{
		printf("-->[%d]", g->data);
		g = g->next;
	}
	printf("\n");

	while(address_temp != NULL)
	{
		printf("-->[%p]", address_temp->next);
		address_temp = address_temp -> next;
	}
	printf("\n");
}



	
