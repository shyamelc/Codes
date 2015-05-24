#!/usr/bin/env python3
test = int(input())
mod = (10**9) + 7
for i in range(test):
    n = int(input())
    n -= 1
    x = (((n*n)-n+6)//2)%(mod)
    print(x)
