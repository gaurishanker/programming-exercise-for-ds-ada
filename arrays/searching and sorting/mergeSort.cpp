#include "iostream"
using namespace std;


void merge(int a[],int l,int m, int r);
void mergeSort(int a[],int l,int r)
{
	if(l<r)
	{
		int mid= (l+r)/2;
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}

void merge(int a[],int l,int mid,int r)
{
	int n1=mid-l+1;
	int n2= r-mid;

	int L[n1];
	for(int i=0;i<n1;++i)
		L[i] = a[l+i];
	int R[n2];
	for(int j=0;j<n2;++j)
		R[j] = a[j+mid+1];
	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<R[j])
		{
			a[k]=L[i];
			i++;
			k++;
		}
		else if(L[i]>R[j])
		{
			a[k]=R[j];
			k++;
			j++;
		}
	} 

	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	}
}

int main(int argc, char const *argv[])
{
	int a[]= {7,6,5,4,3,2,1};
	int n = sizeof(a)/sizeof(int);
	cout<<"Unsorted array \n";
	for(int i=0;i<n;++i)
		cout<<a[i]<<" ";
	mergeSort(a,0,n-1);
	cout<<"\nsorted array \n";
	for(int i=0;i<n;++i)
		cout<<a[i]<<" ";	
	return 0;
}