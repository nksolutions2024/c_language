#include<stdio.h>
#include<string.h>

struct emp_data{
	int empid;
	char empName[20];
	int salary;
	int yearOfJoin;
}arr_struct[10];

void total_salary();
void average_salary();
void maxSalary();
void minSalary();
void findServiceDur();
int serviceDur=0;

int main(){
	arr_struct[0].empid = 101;
	strcpy(arr_struct[0].empName,"tom daves");
	arr_struct[0].salary = 40000;
	arr_struct[0].yearOfJoin = 2008;

	arr_struct[1].empid = 102;
	strcpy(arr_struct[1].empName,"jake");
	arr_struct[1].salary = 36000;
	arr_struct[1].yearOfJoin = 2020;

	for(int i=0; i<2; i++)
	{
		printf("%d\n", arr_struct[i].empid);
		printf("%s\n", arr_struct[i].empName);
		printf("%d\n", arr_struct[i].salary);
		printf("%d\n", arr_struct[i].yearOfJoin);
	}

	total_salary();



}

void total_salary(){
	int total_salary = 0;
	for(int i=0; i<2; i++){
		total_salary = total_salary + arr_struct[i].salary;
	}
	printf("total salary of all emp is %d\n", total_salary);
}

void findServiceDur(){
	serviceDur = 2025 - arr_struct[0].yearOfJoin;
}
