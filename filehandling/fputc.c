#include<stdio.h>

int main(){
	FILE *fs,*ft;
	char ch;
	fs = fopen("fgetc.c", "r");
	ft = fopen("PR2.c", "w");
	while(1)
	{
		ch = fgetc(fs);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			//parameters are char, file-pointer
			fputc(ch, ft);
		}
	}
	fclose(fs);
	fclose(ft);
	printf("\n copied successfully\n");
}
