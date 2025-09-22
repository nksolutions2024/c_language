#include<stdio.h>

void main(){
	char bookname[] = "bookxyz";
	int i=0;

	while(bookname[i]!='\0')
	{
		printf("%c", bookname[i]);
		i++;
	}
	printf("\n");
}
