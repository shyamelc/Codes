#https://www.hackerrank.com/contests/w8/challenges/counter-game

#!/usr/bin/env python3
import math

test = int(input())
for i in range(test):
    n = int(input())
    ans = 0
    while n!=1:
        ans += 1
        po = math.log2(n)
        ipo = int(po)
        if po == ipo:
            n /= 2
        else:
            n = n - 2**ipo
    if ans%2==0:
        print("Richard")
    else:
        print('Louise')