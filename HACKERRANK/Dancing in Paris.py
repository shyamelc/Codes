#!/usr/bin/env python3
#https://www.hackerrank.com/contests/infinitum-jun14/challenges/dance-class

import math

test = int(input())
for _ in range(test):
    value = int(input())
    n = math.ceil(math.sqrt(value+1)) - 1
    if n%2 == 0:
        print('even')
    else:
        print('odd')