#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int no_of_cust = 0; //initial zero customers

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
void withdMoney();
void open_account(int, int, char *);

int main(){
	int choice;
	int temp1,temp2,temp3,temp4, temp5,temp6,temp7,temp8;
	int assigned_no;
	char *name;
	printf("outside while\n");

	dummyEntries();
	display();

	while(1)
	{
		printf("Enter 2->deposit 3->withdraw 6->displayall 9->exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter name :\n");
				scanf("%s", name);
				printf("Enter initial amount :\n");
				scanf("%d",&temp5);
				//mapping
				assigned_no = 100+no_of_cust++;
				//call func
				open_account(assigned_no, temp5, name); //trying
				break;

			case 6:
				display();
				break;

			case 2:
				//parameters are accNo , amount
				printf("Enter acc no: \n");
				scanf("%d", &temp1);
				printf("Enter amount to be deposited: \n");
				scanf("%d", &temp2);
				depositMoney(temp1, temp2);
				break;

			case 3:
				printf("Enter acc no. \n");
				scanf("%d",&temp3);
				printf("Enter amount for withdrawal: \n");
				scanf("%d",&temp4);
				//parameters are accNo, w_amount
				withdMoney(temp3, temp4);
				break;

			case 9:
				exit(0);
		}
	}

}

void open_account(int special_no, int init_amt, char *temp_name){
	int otemp1, otemp2;
	k[special_no].accNo = 100+special_no;
	k[special_no].initAmt = init_amt;
	//account opening time,
	//Balance = initial amount
	k[special_no].balance = init_amt;
	strcpy(k[special_no].custName, temp_name);	
}

void withdMoney(int a, int w_amount){
	int mappedNo, WDAmount, wtemp1;
	WDAmount = w_amount;
	mappedNo = a-100;

	//only if wtemp1 >= 0
	wtemp1 = (k[mappedNo].balance - WDAmount);
	
	k[mappedNo].balance = wtemp1;
	printf("withdraw sucessful\n");	
}

void depositMoney(int a, int d_amount){
	int mappedNo, depAmount;
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
