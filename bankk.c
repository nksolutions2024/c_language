#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cust_detail{
	int accNo;
	int initAmt;
	int balance; //first time , balance is equal to initAmt
	char custName[40];
};

void dummyEntries();
void display();

int main(){
	int choice;
	printf("outside while\n");

	dummyEntries();
	display();

	while(1)
	{
		printf("Enter 1-> 9->exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("hhello, you typed one\n");
				break;

			case 9:
				exit(0);
		}
	}

}

void dummyEntries(){
	struct cust_detail *s_ptr_temp1, *s_ptr_temp2;
	s_ptr_temp1=(struct cust_detail *)malloc(sizeof(struct cust_detail));
	s_ptr_temp2=(struct cust_detail *)malloc(sizeof(struct cust_detail));

	s_ptr_temp1->accNo = 100;
	s_ptr_temp1->initAmt = 3584;
	s_ptr_temp1->balance = s_ptr_temp1->initAmt;
	strcpy(s_ptr_temp1->custName, "Gopal");
	
	s_ptr_temp1->accNo = 101;
	s_ptr_temp1->initAmt = 4538;
	s_ptr_temp1->balance = s_ptr_temp1->initAmt;
	strcpy(s_ptr_temp1->custName, "Gopal1");
	
}

void display(){
	for(int i=0; i<2; i++)
	{
		//it will not work as 
		//s_ptr_temp1 is local to above function
		printf("acc no %d\n", s_ptr_temp1->accNo);

		printf("/n");
	}
}
