#include <iostream>
using namespace std;

// function implementing binary search
int search(int a[],int l,int r,int x)
{
    if(r>=l)
    {
        int mid=l+(r-l)/2;
        if(a[mid]==x)
            return mid;
        if(a[l]<=a[mid])
        {
            if(a[l]<=x && a[mid] > x)
                return search(a,l,mid-1,x);
            else
                return search(a,mid+1,r,x);
        }
        else
        {
            if(a[mid] < x && a[r] >= x )
                return search(a,mid+1,r,x);
            else
                return search(a,l,mid-1,x);
        }
    }
    return -1;
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
	    int x;
	    cin>>x;
	    cout<<search(a,0,n-1,x)<<endl;
	    t--;
	}
	return 0;
}