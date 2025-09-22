#include<stdio.h>
#include<stdlib.h>

struct player_info{
	int id;
};

int main(){
	
	struct player_info *p[100];

	void* ptr;
	ptr = malloc(sizeof(struct player_info)); // ptr gets 8bytes

	struct player_info* s_ptr; //pointer to structure

	s_ptr = (struct player_info *)ptr; //typecasting
////////////////////////////////////////////////////////////////////
	p[0] = (struct player_info *)malloc(sizeof(struct player_info));

	scanf("%d",&s_ptr->id);
	p[0] = s_ptr;
	printf("\n %d \n", p[0]->id);


	return 0;
}
