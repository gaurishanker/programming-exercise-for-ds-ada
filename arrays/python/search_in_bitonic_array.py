#code
def lsearch(a,l,h,x):
    # print("bsearch(a,{},{},{})".format(l,h,x));
    if l>h:
        return -1
    mid=(l+h)//2
    if a[mid]==x:
        return mid
    if x<a[mid]:
        return lsearch(a,l,mid-1,x)
    return lsearch(a,mid+1,h,x)
    
def rsearch(a,l,h,x):
    # print("bsearch(a,{},{},{})".format(l,h,x));
    if l>h:
        return -1
    mid=(l+h)//2
    if a[mid]==x:
        return mid
    if x>a[mid]:
        return rsearch(a,l,mid-1,x)
    return rsearch(a,mid+1,h,x)
    
def bsearch(a,l,h):
    if l>h:
        return -1
    
    # print("bsearch(a,{},{},{})".format(l,h,x));
    mid=(l+h)//2
    if (mid==l or a[mid]>a[mid-1]) and (mid==h or a[mid]>a[mid+1]):
        return mid
    if a[mid]>a[mid-1]:
        return bsearch(a,mid+1,h)
    return bsearch(a,l,mid-1)
    
t=int(input())
while t>0:
    n,x=[int(i) for i in input().split(' ') if i!= '' ]
    a=[ int(i) for i in input().split(" ") if i != '' ]
    pivot=bsearch(a,0,n-1)
    # print(a[pivot])
    if pivot != -1:
        first = lsearch(a,0,pivot,x)
        if first==-1:
            first = rsearch(a,pivot,n-1,x)
        if first==-1:
            print("OOPS! NOT FOUND")
        else:
            print(first)
    else:
        print("OOPS! NOT FOUND")
    t-=1
