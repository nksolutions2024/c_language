#include<stdio.h>

void area_cal(int* m, int* n);

struct rect {
	int length;
	int breadth;
	int area;
};

int main(){
	int i;
//	struct rect svar;
	struct rect svar[3];
	struct rect *sptr;

//	scanf("%d",&svar.length);
//	scanf("%d",&svar.breadth);

	for(i=0; i<3; i++)
	{
		scanf("%d",&svar[i].length);
		scanf("%d",&svar[i].breadth);
		svar[i].area = svar[i].length * svar[i].breadth;
	}

	for(i=0; i<3; i++)
	{
		printf("\n %d \n", svar[i].area);
	}

	return 0;
}

void area_cal(int* m, int* n)
{
	return (*m)*(*n);
}

//_fpurge(stdin);
