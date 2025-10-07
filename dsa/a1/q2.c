#include<stdio.h>

struct emp_data{
	int empid;
	int yearOfJoin;
}emp1,emp2;

int main(){
	emp1.empid = 101;
	emp1.yearOfJoin = 2008;

	printf("%d\n", emp1.empid);
	printf("%d\n", emp1.yearOfJoin);
   	

}
