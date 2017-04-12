#include "stdio.h"
#include "stdlib.h"

void insertionSort(int *a,int n)
{
	for(int i=1;i<n;++i)
	{
		int key=*(a+i),j=i-1;
		for(;j>=0 && key < *(a+j);--j)
		{
			*(a+j+1)=*(a+j);
		}
		*(a+j+1)=key;
	}	
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int *a = (int*)malloc(n*sizeof(int));
	printf("Enter values for array : \n");
	for(int i=0;i<n;++i)
		scanf("%d",(a+i));
	printf("Entered array is :\n");
	for(int i=0;i<n;++i)
		printf("%d ", *(a+i));
	insertionSort(a,n);
	printf("\nAfter Sorting array is :\n");
	for(int i=0;i<n;++i)
		printf("%d ", *(a+i));
	free(a);
	return 0;
}