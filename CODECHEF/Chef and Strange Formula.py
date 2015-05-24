#!/usr/bin/env python3
#http://www.codechef.com/FEB15/problems/STFM/
facto = [0]*1000000
def getfacto(x):
    if x<1000000:
        return facto[x]
    if(x >= m):
        return 0
    return (x*getfacto(x-1))%m
    

stri = input().split()
n = int(stri[0])
m = int(stri[1])

facto[0] = facto[1] = 1
for i in range(2,1000000):
    facto[i] = (facto[i-1]*i)%m
#for i in range(10):
#    print(facto[i],end=' ')
ans=0
stri = input().split()
for i in range(n):
    t = int(stri[i])
    ans = (ans + getfacto(t+1) + (t*t*(t+1)//2)%m -1)%m
print(ans)