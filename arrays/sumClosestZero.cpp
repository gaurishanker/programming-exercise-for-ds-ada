#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;


void insertionSort(int a[],int n)
{
    for(int i=1;i<n;++i)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main() {
	//code
	int t;
	cin>>t;
	while(t>0)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;++i)
	        cin>>a[i];
	    insertionSort(a,n);
	    int i=0,j=n-1;
	    int min = abs(a[i] + a[j]);
	    int k=a[0],l=a[n-1];
	    while(i<j)
	    {
	        if(min>abs(a[i]+a[j]))
	        {
	            min=abs(a[i]+a[j]);
	            k=a[i];
	            l=a[j];
	        }
	       if(a[i]+a[j]>0)
	        j--;
	       else
	        i++;
	    }
	    cout<<k<<" "<<l;
	    t--;
	    cout<<endl;
	}
	return 0;
}