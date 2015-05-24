#!/usr/bin/env python3
catalan = [0]*1001
catalan[0] = catalan[1] = 1
for i in range(2,1001):
    catalan[i] = ((4*i-2)*catalan[i-1]//(i+1))%1000000007
test = int(input())
for i in range(test):
    n = int(input())
    print (catalan[n])