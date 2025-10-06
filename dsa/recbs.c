#include<stdio.h>

int rbinSearch(int arr[], int start, int end, int x){
	if(end >= start)
	{
		int mid = start + (end-start)/2;
		if(arr[mid]==x)
		{
			return mid;
		}

		if(arr[mid]>x)
		{
			return rbinSearch(arr,start,mid-1,x);
		}
		else
		{
			return rbinSearch(arr, mid+1, end, x);
		}
	}
	return -1;
}

int main(){
	int arr[]={10,20,30};
	int n = sizeof(arr) / sizeof(arr[0]);
       	int x = 20;

	int result = rbinSearch(arr, 0, n - 1, x);
	if (result != -1)
        	printf("Element found at index %d\n", result);
    	else
        	printf("Element not found\n");

    	return 0;
//	printf("\n%d\n", rbinSearch(arr,10,30,20) );
}

//not working ; giving garbage
