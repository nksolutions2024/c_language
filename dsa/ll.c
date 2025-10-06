#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* head = NULL;

void insert(int);
void display();

int main(){
	int ele;
	int choice;

	while(1)
	{

	printf("enter 1->insert 2->display 3->exit \n");
	scanf("%d", &choice);

	switch(choice){
		case 1: printf("enter ele \n");
			scanf("%d", &ele);
			insert(ele);
			break;
		case 2: printf("linklist \n");
			display();
			break;
		case 3: 
			exit(0);
	}
	}

}

void insert(int ele){
	struct node* temp;
	void* v_ptr = malloc(sizeof(struct node));
	temp = (struct node*)v_ptr;

	temp->data = ele;
	temp->next = NULL;

	if (head == NULL){
		head = temp;
		return;
	}

	struct node* t1;
	t1=head;

	//purpose of it ?
	while(t1->next != NULL){
		t1=t1->next;
	}
	t1->next = temp;

}

void display(){
	struct node* t1;
	t1=head;

	while(t1 != NULL) //try next
	{
		printf("-->[%d]", t1->data);
		t1=t1->next;
	}
	printf("\n");
}

/*
enter 1->insert 2->display 3->exit
1
enter ele
10
enter 1->insert 2->display 3->exit
1
enter ele
20
enter 1->insert 2->display 3->exit
1
enter ele
30
enter 1->insert 2->display 3->exit
2
linklist
-->[10]-->[20]-->[30]
enter 1->insert 2->display 3->exit
1
enter ele
40
enter 1->insert 2->display 3->exit
2
linklist
-->[10]-->[20]-->[30]-->[40]
enter 1->insert 2->display 3->exit
3
*/
