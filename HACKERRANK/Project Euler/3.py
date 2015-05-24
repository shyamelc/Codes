#!/usr/bin/env python3
#https://www.hackerrank.com/contests/project-euler/challenges/euler003
import math
limit = int(math.sqrt(600851475143))
primes = [0]*(limit+1)
primes[0],primes[1] = 1,1
for i in range(2,int(math.sqrt(limit))+1):
    for j in range(i*i, limit, i):
        primes[j] = 1
        
i = limit
while True:
    if not primes[i] and 600851475143%i == 0:
        break
    i -= 1
    
print(i)