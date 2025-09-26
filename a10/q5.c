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

	return 0;
}
