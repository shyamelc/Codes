#http://www.codechef.com/SEPT14/problems/RAINBOWB/
#!/usr/bin/env python3
def combi(n,r):
    r = min(r,n-r)
    ans = 1
    for i in range(1,r+1):
        ans *= n
        n -= 1
    for i in range(2,r+1):
        ans = ans//i
    ans = ans % 1000000007
    return ans

n = int(input())
if n < 13:
    print('0')
else:
    n = (n-13)//2
    ans = 1
    for i in range(1,n+1):
        ans = (ans + combi(i+5,5))%1000000007
    print (ans)