#include<stdio.h>
#include<string.h>

struct emp_data{
	int empid;
	char empName[20];
	int salary;
	int yearOfJoin;
}emp1,emp2;

int main(){
	emp1.empid = 101;
	strcpy(emp1.empName,"strcopy string");
	emp1.salary = 40000;
	emp1.yearOfJoin = 2008;

//	printf("enter the name : ");
//	scanf("%s", emp1.empName);

	printf("%d\n", emp1.empid);
	printf("%s\n", emp1.empName);
	printf("%d\n", emp1.salary);
	printf("%d\n", emp1.yearOfJoin);
   	

}

