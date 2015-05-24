#!/usr/bin/env python3
#http://www.spoj.com/SPC02/problems/SPCP01/
n = int(input())
#stri = input().split()
numbers = [int(x) for x in input().split()]
numbers.sort()
count = 0
j = 1
for i in range(n):
    count += abs(j-numbers[i])
    j += 1
    
print(count)