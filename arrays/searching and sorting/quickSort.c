#include "stdio.h"
#include "stdlib.h"

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

int partition(int a[],int low,int high,int n)
{
	int p = a[high];
	int i= low-1,j;
	for(j=low;j<=high-1;++j)
	{
		if(a[j]<=p)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);

	return i+1;
}

void quickSort(int a[],int low,int high,int n)
{
	if(low<high)
	{
		int p = partition(a,low,high,n);
		quickSort(a,low,p-1,n);
		quickSort(a,p+1,high,n);
	}
}


int main(int argc, char const *argv[])
{
	int a[]={10,80,30,90,40,50,70};
	int n = sizeof(a)/sizeof(int);
	printf("Array before quick sort\n");
	for(int i=0;i<n;++i)
		printf("%d ",a[i]);
	quickSort(a,0,n-1,n);
	printf("Array after quick sort\n");
	for(int i=0;i<n;++i)
		printf("%d ",a[i]);
	return 0;
}