#code
def bsearch(a,l,h,n):
    if l<=h:
        print("bsearch(a,{},{},{})".format(l,h,x));
        mid=(l+h)//2
        if a[mid]==n:
            return mid
        if a[l]<a[mid]:
            if a[l]<=n and n<=a[mid]:
                return bsearch(a,l,mid-1,n)
            else:
                return bsearch(a,mid+1,h,n)
        else:
            if a[mid]<=n and n<=a[h]:
                return bsearch(a,mid+1,h,n)
            else:
                return bsearch(a,l,mid-1,n)
    
t=int(input())
while t>0:
    n,x=[int(i) for i in input().split(' ') if i!= '' ]
    a=[ int(i) for i in input().split(" ") if i != '' ]
    print(bsearch(a,0,n-1,x))
    t-=1
