/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers.
By convention, 1 is included. Write a program to find Nth Ugly Number.
*/

#include <iostream>
using namespace std;

int min(int a,int b)
{
	return a>b?b:a;
}


int main() {
	//code
	int t;
	cin>>t;
	int ugly[500];
	ugly[0]=1;
	int i2=0,i3=0,i5=0,i=1;
	while(i<500)
	{
	    int n2 = ugly[i2]*2;
	    int n3 = ugly[i3]*3;
	    int n5 = ugly[i5]*5;
	    int next = min(n2,min(n3,n5));
	    if(next == n2)
	    {
	        i2++;
	    }
	    if(next == n3)
	        i3++;
	    if(next == n5)
	        i5++;
	    ugly[i]=next;
	    i++;
	}
	while(t>0)
	{
	    int n;
	    cin>>n;
	    cout<<ugly[n-1]<<endl;
	    t--;
	}
	return 0;
}