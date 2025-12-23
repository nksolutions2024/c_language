#include<stdio.h>

int main(){
	FILE *fs, *ft ;
	char ch;
	fs = fopen("helloworld.c", "r");
	ft = fopen("hello.c", "w");

	while(1)
	{
		ch = fgetc(fs);
		if(ch == EOF)
		{
			break;
		}
		else
		{
			fputc(ch, ft);
		}
	}

	fclose(fs);
	fclose(ft);

	printf("\ncopied sucessfully \n");


	
}
