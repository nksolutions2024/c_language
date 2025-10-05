#include<stdio.h>

int binSearch(int* p, int start, int end, int x);

int main(){
	arr[]={10,20,30};
	binSearch(arr, , ,20); //issue


}

int binSearch(int *p, int start, int end, int x){
	while(start <= end)
	{
		int mid = start + (end-start)/2;
		if(p[mid]==x)
			return mid;
		if(p[mid]<x)
			start=mid+1;
		else
			printf("--");
	}
}

