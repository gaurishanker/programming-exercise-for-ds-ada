#include "stdio.h"

//this function returns the position of fisrt occurence of x
int binarySearch(int a[],int l,int r,int x)
{
	if(l<=r)
	{
		int mid= l+ (r-l)/2;
		if((mid==0 || a[mid-1] != x) && a[mid]==x)
			return mid;
		else if(a[mid] < x)
				return binarySearch(a,mid+1,r,x);
		else
			return binarySearch(a,l,mid-1,x);
	}
	return -1;
}

// This function returns if the given element x is a majority element or not
bool majorityElement(int a[],int n,int x)
{
	int i=binarySearch(a,0,n-1,x); 
	if(i==-1)
		return false;
	if((i+n/2) <= n-1 && a[i+n/2]==x)
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	int a[]={1,2,3,3,3,3,10};
	int n = sizeof(a)/sizeof(int);
	int x=3;
	if(majorityElement(a,n,x))
		printf("\nYes %d is a majority element",x);
	else
		printf("\nNo %d is not majority element",x);
	return 0;
}