#include<stdio.h>

int area_cal(int index,int* m, int* n);

struct rect {
	int length;
	int breadth;
	int area;
};

struct rect svar[3];

int main(){
	int i;
//	struct rect svar;
//	struct rect svar[3];
	struct rect *sptr;

//	scanf("%d",&svar.length);
//	scanf("%d",&svar.breadth);

	for(i=0; i<2; i++)
	{
		scanf("%d",&svar[i].length);
		scanf("%d",&svar[i].breadth);
		printf("\n%d\n",area_cal(i, &svar[i].length, &svar[i].breadth) );
	}

	for(i=0; i<2; i++)
	{
		printf("\n %d \n", svar[i].area);
	}

	return 0;
}

int area_cal(int index,int* m, int* n)
{
	return svar[index].area=(*m)*(*n);
}

//_fpurge(stdin);
