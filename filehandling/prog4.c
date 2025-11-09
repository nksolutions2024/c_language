#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	FILE *fp;
	char str[80];
	fp = fopen("POEM.txt","w");
	if(fp==NULL)
	{
		puts("cannot open file");
		exit(1);
	}
	printf("\n Enter a few lines:\n");
	//gets
	while( strlen(gets(str))>0 )
	{
		//fputs
		fputs(str, fp);
		fputs("\n",fp);
	}
	fclose(fp);
	
	/*read the file back*/
	printf("reading now....\n");
	fp = fopen("POEM.txt","r");
	if(fp==NULL)
	{
		puts("cannot open file"); //try occurence
		exit(2);
	}
	//fgets
	while(fgets(str, 79, fp) != NULL)
	{
		printf("%s", str);
	}
	fclose(fp);
	return 0;
}
