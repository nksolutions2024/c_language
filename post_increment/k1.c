#include<stdio.h>

void main(){
	int k,l,g,h;
	k = 9;
	l = 9;

	g = k++;
	printf("case a: %d\n", g );
	h = ++l;
	printf("case b: %d\n", h );

	printf("case 45: %d\n", g );
	printf("case 78: %d\n", h );

}
