#!/usr/bin/env python3
import math
def combination(a,b):
    answer = 1
    b = min(b,a-b)
    for j in range(1,b+1):
        answer *= (a-j+1)
        answer /= j
    return int(answer)

test = int(input())
for i in range(test) :
    stri = input().split()
    n = int(stri[0])
    k = int(stri[1])
    print(combination(n-1, k-1))