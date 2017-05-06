/*
Given an array of 0s and 1s, find the position of 0 to be replaced with 1 to get longest continuous sequence of 1s. Expected time complexity is O(n) and auxiliary space is O(1).
Input: 
   arr[] =  {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1}
Output:
  Index 9
Assuming array index starts from 0, replacing 0 with 1 at index 9 causes
the maximum continuous sequence of 1s.

Input: 
   arr[] =  {1, 1, 1, 1, 0}
Output:
  Index 4


*/
#include "stdio.h"

// difference between curr zero and prev_prev_zero gives total number of 1's around prev_zero bcoz there is only one zero between them and rest are number of 1's

int flip(int a[],int n)
{
	int max_count =0 ;
	int prev_zero = -1,prev_prev_zero=-1;
	int max_index=-1;
	for(int curr=0; curr <n;++curr)
	{
		if(a[curr]==0)
		{
			if(curr - prev_prev_zero > max_count)
			{
				max_count = curr - prev_prev_zero;
				max_index = prev_zero;
			}
			prev_prev_zero = prev_zero;
			prev_zero = curr;
		}
	}
	if(n-prev_prev_zero > max_count)
		max_index = prev_zero;

	return max_index;

}

int main(int argc, char const *argv[])
{
	int a[]={1,0,0,1,0,1,1,1};
	int n= sizeof(a)/sizeof(n);
	printf("The index to be flipped to get maximum number of ones is %d\n",flip(a,n));
	return 0;
}