#include<stdio.h>
void sort(int arr[], int n);

int main(){
	arr[5]={10,30,50,40,20};
	sort(arr, 5); //calling function
}

void sort(int arr[], int n){
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp;
				temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}


