
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// A structure to store an element and its current count
/* struct eleCount
{
    long long int e;  // Element
    long long int c;  // Count
};
*/
// Prints elements with more than n/k occurrences in arr[] of
// size n. If there are no such elements, then it prints nothing.
void moreThanNdK(long long int a[], long long int n, long long int k)
{
// Your code goes here
    eleCount temp[k-1];
    for(int i=0;i<k-1;++i) {
        temp[i].c=0;
    }
    for(int i=0;i<n;++i) 
    {
        int s=0; // check whether element exists in temp or not
        for(s=0;s<k-1;++s) {
            if(temp[s].e==a[i]) {
                temp[s].c++;
                break;
            }
        }
        if(s==k-1) {
            int l=0; // insert if empty position exists
            for(l=0;l<k-1;++l) {
                if(temp[l].c==0) {
                    temp[s].e=a[i];
                    temp[s].c++;
                    break;
                }
            }
            if(l==k-1) {
                //decrement count
                for(int d=0;d<k-1;d++) {
                    temp[d].c--;
                }
            }
            
        }
    }
    int res=0;
    for(int l=0;l<k-1;++l) 
    {
        int count=0;
        for(int po=0;po<n;++po) 
        {
            if(a[po]==temp[l].e) {
                count++;
            }
        }
         printf("%d",temp[i]);
        if(count>n/k) {
            res++;
        }
    }
    cout<<res<<endl;
}
