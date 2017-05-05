#include "stdio.h"
#include "stdlib.h"

int search(int a[],int l,int r,int n,int key)
{
	if(l<=r)
	{
		int mid = (l+r)/2;
		if(a[mid] == key)
			return mid;
		if(mid==0 || a[mid-1]== key)
			return mid-1;
		if(mid+1== n-1 || a[mid+1] == key)
			return mid+1;
		if(a[mid]>key)
			return search(a,l,mid-2,key,n);
		return search(a,mid+2,r,key,n);

	}
	return -1;
}


int main(int argc, char const *argv[])
{
	int a[]={10, 3, 40, 20, 50, 80, 70};
	int key = 40;
	int n = sizeof(a)/sizeof(int);
	printf("Index of %d in the given array is %d",key,search(a,0,n,n,key) );
	return 0;
}