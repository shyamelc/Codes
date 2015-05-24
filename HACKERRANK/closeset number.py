#!/usr/bin/env python3
#https://www.hackerrank.com/contests/w5/challenges/closest-number
#See editorial for better explanation
test = int(input())
for _ in range(test):
    stri = input().split()
    a,b,x = int(stri[0]),int(stri[1]),int(stri[2])
    aRb = a**b
    multiple = aRb//x
    multiple2 = multiple + 1
    multiple3 = multiple - 1
    first = multiple*x
    second = multiple2*x
    third = multiple3*x
    
    if abs(first-aRb) <= abs(second-aRb) and abs(first-aRb) <= abs(third-aRb):
        print(int(first))
    elif abs(second-aRb) <= abs(first-aRb) and abs(second-aRb) <= abs(third-aRb):
        print(int(second))
    else:
        print(int(third))
    