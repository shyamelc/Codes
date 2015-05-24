#!/usr/bin/env python3
#http://www.codechef.com/JUNE14/problems/GUESS
import math
from fractions import gcd

test = int(input())
for i in range(test):
    stri = input().split()
    m = int(stri[0])
    n = int(stri[1])
    result = (m//2)*(n - n//2) + (n//2)*(m - m//2)
    denominator = m*n
    divisor = gcd(result,denominator)
    result /= divisor
    denominator /= divisor
    print(str(int(result))+'/'+str(int(denominator)))
        
