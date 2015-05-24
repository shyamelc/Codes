#!/usr/bin/env python3
#https://www.hackerrank.com/contests/w5/challenges/even-odd-query
n = int(input())
numbers = [int(x) for x in input().split()]
Q = int(input())
for _ in range(Q):
    stri = input().split()
    x,y = int(stri[0])-1, int(stri[1])-1
    
    if numbers[x]%2==0:
        odd = False
    else:
        odd = True
    if x > y:
        print('Odd')
    elif x==y:
        if odd:
            print('Odd')
        else:
            print('Even')
    else:
        if numbers[x]==0:
            print('Even')
        elif numbers[x+1]==0:
            print('Odd')
        elif odd:
            print('Odd')
        else:
            print('Even')