#include<stdio.h>

struct form{
	char name[45];
	int age;
	char gender[6];
	char city[18];
	int pincode;
	char marital_status[3];
	int salary;
}emp_list[40];

int main(){
	int i;
	
	scanf("%s", &emp_list[0].name);
	scanf("%d", &emp_list[0].age);
	scanf("%d", &emp_list[0].pincode);
	scanf("%d", &emp_list[0].salary);
				
	for(i=0; i<1; i++)
	{
		printf("\n %s \n", emp_list[i].name);
		printf("\n %d \n", emp_list[i].age);
		printf("\n %d \n", emp_list[i].pincode);
		printf("\n %d \n", emp_list[i].salary);
	}


	return 0;
}

