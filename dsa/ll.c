#include<stdio.h>

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

	printf("enter \
1->insert \
2->display \
3->exit \n");

}
