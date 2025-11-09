#include<stdio.h>

int main(){
	FILE *fp = fopen("data2.txt", "w+");
	if(fp==NULL)
	{
		printf("unable to open file");
		return -1;
	}

	char str[100];

	//fgets
	fgets(str, sizeof(str), stdin);

	//fputs
	fputs(str, fp);

	printf("%ld \n", ftell(fp));

	rewind(fp);
	printf("after rewind %ld \n", ftell(fp));

	char read[100];
	//fgets
	while(fgets(read, 100, fp) != NULL)
	{
		//puts
		puts(read);
	}

	fclose(fp);
	return 0;
}
