#include<stdio.h>

int main(){
	FILE *fp = fopen("demo.txt","w+");

	if (fp == NULL)
	{
		printf("file open failed! \n");
		return -1;
	}

	fputs("Hello, djnj fdnn fndnjn fndffl!!", fp);
	fseek(fp, 6, SEEK_SET);
	printf("Position after SEEK_SET(6): %ld\n", ftell(fp));	
/*
	for(int i=0; i<2; i++)
	{
		char ch = fgetc(fp);
		printf("\n %c \t",ch);
		fp++;
	}
*/
	char ch;
	while()
	//move 2 bytes forward from current position
	fseek(fp, 2, SEEK_CUR);
	printf("position after SEEK_CUR(2): %ld\n", ftell(fp));

	//back from end of file ; SEEK_END(-5)
	
	fclose(fp);

	return 0;
}

