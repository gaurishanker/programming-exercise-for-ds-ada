#code
t=int(input())
while t>0:
    res=1
    n=int(input())
    a=[ int(i) for i in input().split(" ") if i != '' ]
    for i in range(2,n+1):
        res^=i
    for i in a:
        res^=i
    print(res)
    t-=1
