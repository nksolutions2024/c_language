#include<stdio.h>

void main(){
	char bookname[] = "bookxyz22";
	char *c_ptr;
	c_ptr = bookname;
	
	while( *c_ptr != '\0')
	{
		printf("%c", *c_ptr);
		c_ptr++;
	}
	printf("\n");
}
