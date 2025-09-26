#include<stdio.h>

int main(){
	FILE *fp = fopen("data2.txt", "w+");

	if(fp == NULL)
	{
		printf("Unable to open file for writing\n");
		return -1;
	}
	printf("file pointer position = %ld\n", ftell(fp));

	char str[100];

	fgets(str , sizeof(str), stdin);

	//put string in file	
	fputs(str, fp);

	printf("checkpoint 1\n");
	printf("file pointer position = %ld\n", ftell(fp));


	char read[100];
	while(fgets(read, 100, fp) != NULL)
	{
		puts(read);
	}

	fclose(fp);

	return 0;
}














