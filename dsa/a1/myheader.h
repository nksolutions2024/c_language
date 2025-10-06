#ifndef MYHEADER_H
#define MYHEADER_H

void insertAtIndex(int n,int index){
	// index above 4 ,warning
	//
	if(arr[index] == -99)
	{
		arr[index]=n;
	}
	else
	{
		printf("already element there\n");
	}
}

void display(){
	int i;
	for(i=0; i<5; i++)
	{
		printf("%d\n",arr[i]);
	}
}

void deleteByIndex(int index){
	if (arr[index] != -99)
	{
		printf("Deleted element was %d\n",arr[index]);
		arr[index] = -99;
	}
	else
	{
		printf("Already empty\n");
	}

}

void deleteByEle(int ele)
{
	for(int i=0; i<5; i++)
	{
		if(arr[i] == ele)
		{
			arr[i]=-99;
		}
		//consider case of not found
	}
}

int arrMin(){
	//assume arr[0] is Min 
	//assuming arr[0] is not -99
	int minIndex = 0;
	for(int i; i<5; i++)
	{
		if(arr[i]<arr[minIndex] && arr[i]!=-99)
		{
			minIndex=i;
		}
	}
	return minIndex;
}

#endif
