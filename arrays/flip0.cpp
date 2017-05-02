#include <iostream>
using namespace std;
// program to flip m zeroes into 1 so that we can have maximum number of consecutive ones
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
	    int m;
	    cin>>m;
	    int wL=0,wR=0;
	    int max=0,count=0;
	    while(wR<n)
	    {
	        if(count <= m)
	         {
	         	if(a[wR]==0)
	         		count++;
	         	wR++;
	         }
	        if(count > m)
	        {
	            if(a[wL]==0)
	                count--;
	           wL++;
	        }
	       if(max < wR-wL)
	           max=wR-wL;
	       
	    }
	    cout<<max<<endl;
	    t--;
	}
	return 0;
}
