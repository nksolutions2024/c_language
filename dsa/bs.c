#include<stdio.h>

int binSearch(int* p, int start, int end, int x);

int main(){
	int arr[]={1,2,3,4,5,6,10,20,30}; //must be ascending sorted
	int size = sizeof(arr)/sizeof(arr[0]);

	int result = binSearch(arr, 0, size-1, 20); //issue
	
	if (result != -1)
	{
		printf("element found at index %d\n", result);
	}
	else
	{
		printf("element not fond \n");
	}

	return 0;
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
			end=mid-1;
	}

	return -1; //not found
}

