#include<iostream>
using namespace std;

int searchf(int a[],int l,int r,int x,int n)
{
    if(l<=r){
        int mid=(l+r)/2;
        if((mid==0||a[mid-1]<x)&& a[mid]==x)
            return mid;
        if(a[mid] >= x)
            return searchf(a,l,mid-1,x,n);
        
        return searchf(a,mid+1,r,x,n);
    }
    return -1;
}

int searchl(int a[],int l,int r,int x,int n)
{
    if(l<=r){
        int mid=(l+r)/2;
        if((mid==n-1||a[mid+1]>x)&& a[mid]==x)
            return mid;
        if(a[mid] <= x)
            return searchl(a,mid+1,r,x,n);
        
        return searchl(a,l,mid-1,x,n);
    }
    return -1;
}
int main()
 {
	//code
        int t;
        cin>>t;
        while(t>0)
        {
            int n,x;
            cin>>n>>x;
            int a[n];
            for(int i=0;i<n;++i)
                cin>>a[i];
            int first=searchf(a,0,n-1,x,n);
            int last=searchl(a,0,n-1,x,n);
            if(first == -1)
                cout<<-1<<endl;
            else if(first==last)
                cout<<1<<endl;
            else
                {
                    cout<<last-first+1<<endl;
                }
            t--;
        }
        
	return 0;
}