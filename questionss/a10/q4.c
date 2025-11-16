#include<stdio.h>

int main(){
	FILE *fp = fopen("hello.txt","w+");

	if(fp == NULL)
	{
		printf("error while w+ mode");
		return -1;
	}

	char str[] = "Welcome to my world";

	fputs(str, fp);


	return 0;
}

