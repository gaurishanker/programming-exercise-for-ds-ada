#include <stdio.h>

int findFirstMissing(int array[], int start, int end)
{
	
	if(start<=end)
	{
	int mid = (start + end) / 2;
    
    if((mid==0 || array[mid-1]==mid-1)&& array[mid]>mid)
        return mid;
    
	
	if (array[mid] == mid)
		return findFirstMissing(array, mid+1, end);

	return findFirstMissing(array, start, mid);
	}
	return end+1;
}


int main()
{
	int arr[] = {0, 1, 2, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Smallest missing element is %d",
		findFirstMissing(arr, 0, n-1));
	return 0;
}
