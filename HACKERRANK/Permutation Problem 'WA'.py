#!/usr/bin/env python3
#https://www.hackerrank.com/contests/infinitum-jun14/challenges/permutation-problem
import math

def combination(n,r):
    answer = 1
    r = min(r,n-r)
    answer = 1
    for i in range(1,r+1):
        answer *= (n-i+1)/i
    return answer


test = int(input())
for _ in range(test):
    stri = input().split()
    n, k = int(stri[0]) , int(stri[1])
    answer = 9*(10**(n-1))
    print(answer)
    if k >= n:
        answer = answer %((10**9) + 7)
        print(answer)
    elif k*10 < n:
        print('0')
    else:
        for i in range(k+1,n+1):
            #print(combination(n,i),n,i)
            answer -= (9**(n-i+1))*int(combination(n,i))
            print(n,i,(9**(n-i+1))*int(combination(n,i)))
        answer = answer %((10**9) + 7)
        print(answer)