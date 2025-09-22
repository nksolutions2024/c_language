#include<stdio.h>

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
	
	int yes=1;
	while(yes != 0)
	{
		printf("Enter value of YES(1 or 0) : ");
		scanf("%d", &yes);

		void *ptr;
		ptr = malloc(sizeof(struct student_data));
		struct student_rec * s_ptr;
		s_ptr = (struct student_data *)ptr;
		
		printf("\n Enter name of student-%d: ", no_of_students+1);
		scanf("%s", s_ptr.name);
		printdf("\n Enter age of student-%d: ", no_of_students+1);
		scanf("%d", s_ptr.age);

		blue[no_of_students++] = s_ptr;
	}

	//try function in next phase			
	for(i=0; i<1; i++)
	{
		printf("\n %s \n", blue[i].name);
		printf("\n %d \n", blue[i].age);
	}

	return 0;
}

