#!/usr/bin/env python3
#http://codeforces.com/contest/439/problem/A
stri = input().split()
n = int(stri[0])
d = int(stri[1])
times = []
stri = input().split()
for i in range(n):
    times.append(int(stri[i]))
summation = sum(times)

if((summation + (n-1)*10) <= d):
    count = (n-1)*2
    d -= summation + (n-1)*10
    count += d//5
    print(count)
else :
    print('-1')