#include<stdio.h>

int main(){
	int i =3 ;
	int *j;
	j = &i;
	printf("Address of i = %u\n", &i);
	printf("Address of i = %u\n", j);
	printf("Address of j = %u\n", &j);
	printf("Value of j = %u\n", j);
	printf("Value of i = %d\n", i);
	printf("Value of i = %d\n", *(&i)); 
	printf("Value of i = %d\n", *j);     //dereferencing
}

/* 
Address of i = 3066345900
Address of i = 3066345900
Address of j = 3066345904
Value of j = 3066345900
Value of i = 3
Value of i = 3
Value of i = 3
*/
