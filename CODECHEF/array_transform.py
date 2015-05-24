#!/usr/bin/env python3
#http://www.codechef.com/problems/ARRAYTRM

test = int(input())
for i in range(test):
    stri = input().split()
    n = int(stri[0])
    k = int(stri[1])
    k+=1
    data = [0]*k
    numbers = input().split()
    for j in range(n):
        data[int(numbers[j])%k] += 1
    flag = False    
    for x in data:
        if x>=n-1:
            print('YES')
            flag = True
            break
    if not flag :
        print('NO')