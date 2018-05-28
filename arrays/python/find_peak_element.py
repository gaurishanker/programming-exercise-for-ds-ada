# function should return index to the any valid peak element
def peakElement(a, n):
    # Code here
    i=0
    while i<n :
        if (i==0 or a[i]>a[i-1]) and (i==n-1 or a[i]>a[i+1]) :
            return i
        i+=1
