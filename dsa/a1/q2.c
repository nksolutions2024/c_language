#include<stdio.h>

struct emp_data{
	int empid;
	char empName[20];
	int salary;
	int yearOfJoin;
}emp1,emp2;

int main(){
	emp1.empid = 101;
	emp1.yearOfJoin = 2008;

	printf("enter the name : ");
	scanf("%s", &emp1.empName);

	printf("%d\n", emp1.empid);
	printf("%d\n", emp1.yearOfJoin);
	printf("%s\n", emp1.empName);
   	

}

$ gcc q2.c
q2.c: In function ‘main’:
q2.c:15:17: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[20]’ [-Wformat=]
   15 |         scanf("%s", &emp1.empName);
      |                ~^   ~~~~~~~~~~~~~
      |                 |   |
      |                 |   char (*)[20]
      |                 char *

