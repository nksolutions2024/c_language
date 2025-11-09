#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cust_detail{
	int accNo;
	int initAmt;
	int balance; //first time , balance is equal to initAmt
	char custName[40];
};
struct cust_detail k[100]; //maximum 100 customers

void dummyEntries();
void display();
void depositMoney(int, int);

int main(){
	int choice;
	printf("outside while\n");

	dummyEntries();
	display();

	while(1)
	{
		printf("Enter 2->deposit 6->displayall 9->exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("hhello, you typed one\n");
				break;

			case 6:
				display();
				break;

			case 2:
				depositMoney(123, 100);
				break;

			case 9:
				exit(0);
		}
	}

}

void depositMoney(int a, int d_amount){
	int temp1,temp2,mappedNo, depAmount;
	depAmount = d_amount;
	mappedNo = a-100;

	k[mappedNo].balance = k[mappedNo].balance + depAmount;
	printf("deposit successful \n");
}

void dummyEntries(){
	struct cust_detail *s_ptr_temp1, *s_ptr_temp2;
	s_ptr_temp1=(struct cust_detail *)malloc(sizeof(struct cust_detail));
	s_ptr_temp2=(struct cust_detail *)malloc(sizeof(struct cust_detail));

	s_ptr_temp1->accNo = 100;
	s_ptr_temp1->initAmt = 3584;
	s_ptr_temp1->balance = s_ptr_temp1->initAmt;
	strcpy(s_ptr_temp1->custName, "Gopal");
	//dereference required of struct-pointer
	k[0] = *s_ptr_temp1; //copying struct
	
	s_ptr_temp2->accNo = 101;
	s_ptr_temp2->initAmt = 4538;
	s_ptr_temp2->balance = s_ptr_temp2->initAmt;
	strcpy(s_ptr_temp2->custName, "Gopal1");
	k[1] = *s_ptr_temp2;
	
}

void display(){
	for(int i=0; i<2; i++)
	{
		//k[0] is not struct-pointer
		// so, must use dot(.) operator 
		printf("acc no %d,when i=[%d]\n", k[i].accNo, i);
		printf("initAmt %d\n", k[i].initAmt);
		printf("balance %d\n", k[i].balance);
		printf("customer name: %s\n", k[i].custName);

		printf("\n");
	}
}
