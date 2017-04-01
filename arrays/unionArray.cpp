//Given two arrays A and B, find union between these two array.  
//If there are repetitions, then only one occurrence of element should be printed in union.

#include <iostream>
using namespace std;

void insertionSort(int a[],int n)
{
    
    for(int i=1;i<n;++i)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0 && key<a[j])
        {
                a[j+1]=a[j];
                j--;
        }
        a[j+1]=key;
    }
}

int main()
 {
	int t;
	cin>>t;
	while(t>0)
	{
	    int n,m;
	    cin>>n>>m;
	    int a[n],b[m];
	    for(int i=0;i<n;++i)
	        cin>>a[i];
	    
	    for(int i=0;i<m;++i)
	        cin>>b[i];
	   insertionSort(b,m);
	   insertionSort(a,n);
	    int i=0,j=0;
	    while(i<n && j<m)
	    {
	        if(a[i]<b[j])
	        {
	            cout<<a[i]<<" ";
	            i++;
	        }
	        else if(a[i]>b[j])
	        {
	            cout<<b[j]<<" ";
	            j++;
	        }
	        else{
	            cout<<a[i]<<" ";
	            ++i;++j;
	        }
	    }
	    while(i<n)
	    {
	        cout<<a[i]<<" ";
	        ++i;
	    }
	    while(j<m)
	    {
	        cout<<b[j]<<" ";
	        j++;
	    }
	    cout<<endl;
	    t--;
	}
        
	return 0;
}