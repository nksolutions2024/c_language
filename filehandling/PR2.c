#include<stdio.h>

int main(){
	//declaring FILE pointer
	FILE *fp;
	char ch;//datatype char; 1 byte
	int nol=0, not=0, nob=0, noc=0;
	//fopen function with 2 arguments
	fp = fopen("fgetc.c","r");
	while(1)
	{
		//storing 1-byte in variable "ch"
		//fgetc func takes file-pointer
		//fgetc reads 1 character at a time
		//somehow increment in next-iteration
		ch = fgetc(fp);
		//EOF is important
		if(ch==EOF)
		{
			break;
		}
		//whatif EOF goes inside printf
		printf("%c",ch);
		//program-2
		noc++;
		if(ch==' ')
			nob++;
		if(ch=='\n')
			nol++;
		if(ch=='\t')
			not++;
	}
	printf("\n-----	---- ---- --\n");
	printf("%d %d %d %d",noc, nob, nol, not);
	
	fclose(fp); //close file pointer
}
