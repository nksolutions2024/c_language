#include<stdio.h>
#include<stdlib.h>

int no_of_students=0;

struct student_data{
	char *name;
	int age;
	char gender[6];
	char city[18];
	int pincode;
	char marital_status[3];
	int salary;
};

int main(){
	int i;
	
	struct student_data *blue[100];
	
	for(i=0; i<1; i++)
	{
		printf("Enter value of YES(1 or 0) : ");

		void *ptr;
		ptr = malloc(sizeof(struct student_data));
		struct student_data * s_ptr;
		s_ptr = (struct student_data *)ptr;
		
		printf("\n Enter age of student-%d: ", no_of_students+1);
		scanf("%d", s_ptr->age);

		blue[no_of_students] = (struct student_data*)malloc(sizeof(struct student_data));
		blue[no_of_students] = s_ptr;
	}

	//try function in next phase			
	for(i=0; i<1; i++)
	{
		printf("\n %d \n", blue[i]->age);
	}

	return 0;
}

