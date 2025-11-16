#include<stdio.h>

struct rect {
	int length;
	int breadth;
	int area;
};

int main(){
	struct rect svar;
	struct rect sarr[3];
	struct rect *sptr;

	scanf("%d",&svar.length);
	scanf("%d",&svar.breadth);

	svar.area = svar.length * svar.breadth;

	printf("\n %d \n", svar.area);



	return 0;
}

