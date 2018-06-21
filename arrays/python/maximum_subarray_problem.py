#code
#explaination 
#https://medium.com/@marcellamaki/finding-the-maximum-contiguous-sum-in-an-array-and-kadanes-algorithm-e303cd4eb98c
t=int(input())
while t>0:
    n=int(input())
    a=[ int(i) for i in input().split(" ") if i != '' ]
    i,j=0,0
    max_so_far=a[i]
    curr_max = a[i]
    i+=1
    while i<n:
        curr_max = max(curr_max+a[i],a[i])
        if max_so_far<curr_max:
            max_so_far = curr_max
        i+=1
    print(max_so_far)
    t-=1