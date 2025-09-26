#include<stdio.h>

int main(){
	FILE *fp = fopen("data1.txt", "w+");
//	FILE *fp = fopen("data1.txt", "a+");

	if(fp == NULL)
	{
		printf("Unable to open file for writing\n");
		return -1;
	}
	printf("file pointer position = %ld\n", ftell(fp));

//	char ch1 = 'A';
	char str[100];

//	fputc(ch1, fp);
	fgets(str , sizeof(str), stdin);

//	printf("file pointer position = %ld\n", ftell(fp));
//	rewind(fp);
/*
	size_t len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	if (len > 0 && str[len-1] == '\n')
	{
		str[len-1] = '\0';
	}
*/	
	fputs(str, fp);



	printf("file pointer position = %ld\n", ftell(fp));
/*
	char ch;
	while((ch = fgetc(fp)) != EOF)
	{
		printf("the char is = %c\n", ch);
	}
*/
	fclose(fp);


	return 0;
}














