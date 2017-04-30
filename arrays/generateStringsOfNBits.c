#include "stdio.h"
#include "stdlib.h"

void binary(char a[],int i,int n)
{
	if(i>=n)
		printf("%s\n", a);
	else
	{
		a[i]='0';
		binary(a,i+1,n);
		a[i]='1';
		binary(a,i+1,n);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	char *a = (char*)calloc(n,sizeof(char));
	binary(a,0,n);
	return 0;
}