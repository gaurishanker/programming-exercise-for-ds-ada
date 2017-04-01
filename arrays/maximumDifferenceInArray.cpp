//Given an array C[] of integers, find out the maximum difference between any two elements such that larger element appears after the smaller number in C[].
//Examples: If array is [2, 3, 10, 6, 4, 8, 1] then returned value should be 8 (Diff between 10 and 2).
// If array is [ 7, 9, 5, 6, 3, 2 ] then returned value should be 2 (Diff between 7 and 9)
#include <iostream>
using namespace std;

int main()
 {
    int t;
    cin>>t;
    while(t>0)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i)
            cin>>a[i];
        int min=a[0];
        int max = -1;
        for(int i=1;i<n;++i)
        {
            if(a[i]<min)
                min=a[i];
            else if(a[i]-min > max)
                max=a[i]-min;
        }
        cout<<max<<endl;
        t--;
    }
return 0;
}