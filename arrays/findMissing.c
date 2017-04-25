/*
Given an Arithmetic progression find the missing number in ap.
*/

#include <iostream>
#include <cmath>
using namespace std;

int findM(int a[]int d,int l,int r)
{
    if(l>=r)
        return -1;
    int mid = (l+r)/2;
    if(a[mid+1]-a[mid]!=d)
        return a[mid]+d;
        
    if(a[mid]-a[mid-1] != d)
        return a[mid-1]+d;
        
    if(mid >0 && a[mid]==a[0]+mid*d)
        return findM(a,n,d,mid+1,r);
    else
        return findM(a,n,d,l,mid-1);
}

int main() {
	int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
        cin>>a[i];
    int d = (a[n-1]-a[0])/n;
    cout<<findM(a,d,0,n-1)<<endl;
	return 0;
}