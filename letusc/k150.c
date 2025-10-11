#include<stdio.h>

int main(){
	int i=3;
	printf("Address of i = %u\n", &i);
	printf("Address of i = %llu\n", &i);
	printf("Address of i = %p\n", &i);

	printf("Value of i = %d \n", i);
	printf("Value of i = %d\n", *(&i));
	return 0;

}

/* output 
 $ ./a.out
Address of i = 2996536196
Address of i = 140727599989636
Address of i = 0x7ffdb29b8384
Value of i = 3
Value of i = 3
*/
