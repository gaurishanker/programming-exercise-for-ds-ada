#include "stdio.h"
#include "stdlib.h"


/*
Dynamic programming 
Below comments are taken from an answer on stackoverflow.com
http://stackoverflow.com/questions/8649845/how-can-i-find-the-maximum-sum-of-a-sub-sequence-using-dynamic-programming

My understanding of DP is about "making a table". In fact, the original meaning "programming" in DP is simply about making tables.

The key is to figure out what to put in the table, or modern terms: what state to track, or what's the vertex key/value in DAG (ignore these terms if they sound strange to you).

How about choose dp[i] table being the largest sum ending at index i of the array, for example, the array being [5, 15, -30, 10]

The second important key is "optimal substructure", that is to "assume" dp[i-1] already stores the largest sum for sub-sequences ending at index i-1, that's why the only step at i is to decide whether to include a[i] into the sub-sequence or not

dp[i] = max(dp[i-1], dp[i-1] + a[i])
The first term in max is to "not include a[i]", the second term is to "include a[i]". Notice, if we don't include a[i], the largest sum so far remains dp[i-1], which comes from the "optimal substructure" argument.

So the whole program looks like this (in Python):

a = [5,15,-30,10]

dp = [0]*len(a)
dp[0] = max(0,a[0]) # include a[0] or not

for i in range(1,len(a)):
    dp[i] = max(dp[i-1], dp[i-1]+a[i]) # for sub-sequence, choose to add or not     


 print(dp, max(dp)) 
The result: largest sum of sub-sequence should be the largest item in dp table, after i iterate through the array a. But take a close look at dp, it holds all the information.

Since it only goes through items in array a once, it's a O(n) algorithm.

This problem seems silly, because as long as a[i] is positive, we should always include it in the sub-sequence, because it will only increase the sum. This intuition matches the code

dp[i] = max(dp[i-1], dp[i-1] + a[i])
So the max. sum of sub-sequence problem is easy, and doesn't need DP at all. Simply,

sum = 0
for v in a:
     if  v >0
         sum += v
However, what about largest sum of "continuous sub-array" problem. All we need to change is just a single line of code

dp[i] = max(dp[i-1]+a[i], a[i])    
The first term is to "include a[i] in the continuous sub-array", the second term is to decide to start a new sub-array, starting a[i].

In this case, dp[i] is the max. sum continuous sub-array ending with index-i.

This is certainly better than a naive approach O(n^2)*O(n), to for j in range(0,i): inside the i-loop and sum all the possible sub-arrays.

One small caveat, because the way dp[0] is set, if all items in a are negative, we won't select any. So for the max sum continuous sub-array, we change that to

dp[0] = a[0]    maximumContiguous
*/
int max(int a,int b)
{
	return a>b?a:b;
}
int UsingDPArray(int *a,int n)
{
	int *d = (int*)calloc(n,sizeof(int));
	d[0]=a[0];
	for(int i=1;i<n;++i)
		d[i] = max(d[i-1]+a[i],a[i]);
	int res=0;
	for (int i = 1; i < n; ++i)
	{
		if(res<d[i])
			res=d[i];
	}
	return res;
}

int UsingDPArrayOpt1(int *a,int n)
{
	int *d = (int*)calloc(n,sizeof(int));
	d[0]=a[0];
	int res=a[0];
	for(int i=1;i<n;++i)
	{
		d[i] = max(d[i-1]+a[i],a[i]);
		if(res<d[i])
			res=d[i];
	}
	return res;
}

int UsingDPArrayOpt2(int *a,int n)
{
	int max_so_far = a[0];		// this is same as d[i-1]
	int max_curr = a[0]; 		// this is same as d[i]
	for(int i=1;i<n;++i)
	{
		max_curr = max(max_curr+a[i],a[i]);
		max_so_far = max(max_so_far,max_curr);
	}
	return max_so_far;
}

int main(int argc, char const *argv[])
{
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a)/sizeof(int);
	int res = UsingDPArrayOpt2(a,n);
	printf("%d\n", res);
	return 0;
}