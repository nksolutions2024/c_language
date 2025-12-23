#include<stdio.h>
#include<stdlib.h>



struct node{
	int data;
	struct node * next;
};
void insertAtEnd(struct node **, int);
void display(struct node *);

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
			insertAtEnd(&head ,ele);
			break;

		case 2:
			display(head);
			break;

		case 3: 
			exit(0);
	}

}

void insertAtEnd(struct node ** p, int ele ){
	struct node * temp ;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = ele;
	temp->next = NULL;

	struct node *t1;
	t1 = *p;

	if(*p ==NULL)
	{
		*p = temp;
		return;
	}

	while(t1->next != NULL){
		t1=t1->next;
	}

	t1->next =temp;

}

void display(struct node * g){
	struct node * addresstemp;
	addresstemp = g;
	while(g != NULL){
		printf("%d ", g->data);
		g=g->next;
	}
	printf("\n");
}


