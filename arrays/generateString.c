#include "stdio.h"
#include "stdlib.h"

void binary(char a[],int n,int k)
{
	if(n<1)
		printf("%s \n",a);
	else
	{
		for(int j=0;j<k;++j)
		{
			a[n-1]=j+'0';
			binary(a,n-1,k);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n=4;
	char *a = (char*)calloc(n,sizeof(char));
	binary(a,n,2);

	free(a);
	return 0;
}