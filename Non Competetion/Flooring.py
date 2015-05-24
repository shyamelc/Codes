#!/usr/bin/env python3

def kpower4(k,M):
    by2 = k//2
    kraise = k**5
    by2raise = by2**5
    ans = 0
    ans += 6*(kraise - by2raise)
    kraise //= k
    by2raise //= by2
    ans += 15*(kraise-by2raise)
    kraise //= k
    by2raise //= by2
    ans += 10*(kraise-by2raise)
    kraise //= (k*k)
    by2raise //= (by2*by2)
    ans += (kraise - by2raise)
    ans = (ans//30 ) % M
    return ans

print(kpower4(10000000000,100000))
test = int(input())
for i in range(test):
    stri = input().split()
    n = int(stri[0])
    m = int(stri[1])
    half = n//2
    answer = n
    for i in range(2,half+1):
        j = i*i
        j = (j*j) % m
        j *= n//i
        answer = (answer + j) % m
    answer = (answer + kpower4(n,m) ) % m
    print(answer)
    