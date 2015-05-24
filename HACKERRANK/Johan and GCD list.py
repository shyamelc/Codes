#!/usr/bin/env python3
#https://www.hackerrank.com/contests/w8/challenges/john-and-gcd-list

def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)

def lcm(a,b):
    return (a*b)//gcd(a,b)

test = int(input())
for i in range(test):
    n = int(input())
    stri = input().split()
    A = [int(x) for x in stri]
    B = [A[-1]]
    #print(B)
    for i in range(n-1,0,-1):
        B.insert(0,lcm(A[i],A[i-1]))
        #print(B)
    B.insert(0,A[0])
    for i in range(n+1):
        print(B[i],end=' ')
    print()
    