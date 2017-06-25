#include "stdio.h"
#include "string.h"

void swap(char *a,char *b)
{
	char temp = *a;
	*a=*b;
	*b = temp;
	return;
}

void permute(char *a,int pos,int n)
{
	if(pos==n-1)
	{
		printf("%s\n",a);
		return;
	}
	else
	{
		for(int i=pos;i<n;++i)
		{
			swap((a+pos),(a+i));
			permute(a,pos+1,n);
			swap((a+pos),(a+i));
		}
		return;
	}
}

int main(int argc, char const *argv[])
{
	char a[] = "ABC";
	permute(a,0,3);
	return 0;
}