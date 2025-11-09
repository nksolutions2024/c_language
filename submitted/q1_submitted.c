#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure creation
struct cust_detail{
	int accNo;
	int initAmt;
	int balance;
	char custName[20];
}arr_struct[40];

void depositMoney(int accNo,int depAmt);
void display();
void withdrawMoney(int accNo, int withAmt);
void create(char* ccname,int temp2, int x );

//this variable will increment with new entry
//this keep record of entries and mapping with structure accordingly
//ex: arr_struct[0] to accNo 100
// [1] to 101
int no_of_customer=0;

int main(){
	int choice,temp2,temp3,temp4,temp5,assigningNo;
	char* ccname;
	//dummpy 2 entries for debugging purpose 
	arr_struct[0].accNo=100; // assigned automatically
	arr_struct[0].initAmt=4000;
	arr_struct[0].balance=4000; //initially same
	strcpy(arr_struct[0].custName,"Gopal");
	arr_struct[1].accNo=101; // assigned automatically
	arr_struct[1].initAmt=5000;
	arr_struct[1].balance=5800; //initially same
	strcpy(arr_struct[1].custName,"Gopal1");
	
	while(1){
		printf("enter 1->create 2->deposit 3->withdraw 6->displayall 7->exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter name: \n");
				scanf("%s",ccname);
				printf("Enter inital amount: \n");
				scanf("%d",&temp5); //init amt
				printf("\n");
				assigningNo = 100+no_of_customer; 	//assigning acc no. and mapping
				create(ccname, temp5, assigningNo );  //assigning acc no. and mapping
				break;
			case 2:
				printf("please enter your acc no. \n");
				scanf("%d",&temp4);
				getchar();
				printf("enter deposit amt\n");
				scanf("%d",&temp3);
				depositMoney(temp4, temp3 );
				display(); //temp2
				break;
			case 3:
				printf("please enter your acc no. \n");
				scanf("%d",&temp4);
				printf("enter withdraw amt\n");
				scanf("%d",&temp3);
				withdrawMoney(temp4, temp3 );
				break;
			case 6: display();
				break;
			case 7: exit(0);
		}
	}
	
	display();
	depositMoney(100,888);	
	display();
}

void create(char* ccname,int temp5,int assigningNo ){
	int mappedNo = assigningNo-100;
	//below code, storing into particular struct 
	strcpy(arr_struct[mappedNo].custName, ccname);
	arr_struct[mappedNo].initAmt = temp5;
	arr_struct[mappedNo].balance = temp5; //balance is equal to initialAMT
	arr_struct[mappedNo].accNo = assigningNo; 
}

void withdrawMoney(int accNo,int withAmt){
	//
	int temp1,tempWDAmt,mappedNo;
	tempWDAmt = withAmt;
	mappedNo = accNo-100;
	//if temp1>0(i.e balance is enough)
	temp1 = arr_struct[mappedNo].balance -tempWDAmt;
	arr_struct[mappedNo].balance = temp1;	
}

void depositMoney(int accNo,int depAmt){
	//
	int tempAmt,mappedNo;
	tempAmt = depAmt;
	mappedNo = accNo-100;
	//updated balance
	arr_struct[mappedNo].balance = arr_struct[mappedNo].balance + tempAmt; 	
	return;
}

void display(){
	for(int i=0;i<2;i++)
	{
		printf("\n account No. %d \n", arr_struct[i].accNo);
		printf("\n C name %s \n", arr_struct[i].custName);
		printf("\n initial Amt %d \n", arr_struct[i].initAmt);
		printf("\n balance %d \n", arr_struct[i].balance);
		
	}
}
