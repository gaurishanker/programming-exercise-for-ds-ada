#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
 {
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
            sort(a,a+n); // for sorting given array
            int min=a[1]-a[0];  // find minimum difference by comparing difference in adjacent elements of the array
            for(int i=2;i<n;++i)
                if(min>a[i]-a[i-1])
                    min=a[i]-a[i-1];
            cout<<min<<endl;
            t--;
        }
	return 0;
}