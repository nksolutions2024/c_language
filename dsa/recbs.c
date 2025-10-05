#include<stdio.h>

int rbinSearch(int arr[], int start, int end, int x){
	if(end >= start)
	{
		if mid = start + (end-start)/2;
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
		return -1;
	}
}

int main(){
	arr[]={10,20,30};
	printf("\n%d\n", rbinSearch(arr,10,30,20) );
}
