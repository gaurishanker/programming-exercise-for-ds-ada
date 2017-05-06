#include "stdio.h"
#include "stdlib.h"

void swap(int *a, int *b)
{
	int temp =*a;
	*a=*b;
	*b=temp;
}

void sort(int a[],int n)
{
	int i=n-1;
	while(i>0)
	{
		if(a[i]<a[i-1])
		{
			int j=i-1;
			while(j>=0 && a[i]<a[j])
				j--;
			swap(&a[i],&a[j+1]);
			break;
		}
		i--;
	}
}


int main(int argc, char const *argv[])
{
	int a[]={10, 70, 30, 40, 50, 60, 20};
	int n = sizeof(a)/sizeof(int);
	printf("Array before sorting\n");
	for(int i=0;i<n;++i)
		printf("%d ",a[i]);
	sort(a,n);
	printf("\nArray after sorting\n");
	for(int i=0;i<n;++i)
		printf("%d ",a[i]);
	return 0;
}