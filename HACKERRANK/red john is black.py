#!/usr/bin/env python3
#https://www.hackerrank.com/challenges/red-john-is-back
import math
primes = [1]*218001
primes[0] = 0
primes[1] = 0
for i in range(2,int(math.sqrt(218000))+1):
    for j in range(i*i,218000,i):
        primes[j] = 0
for i in range(3,218000):
    primes[i] += primes[i-1]

test = int(input())
for _ in range(test):
    n = int(input())
    if n in range(1,4):
        print('0')
    else:
        least_multiple_4 = n//4
        least_multiple_4 *= 4
        answer = 0
        
        while least_multiple_4 != 0 :
            balls = least_multiple_4//4
            bars = n - balls*4
            answer += math.factorial(balls + bars)//(math.factorial(balls)*math.factorial(bars))
            least_multiple_4 = (least_multiple_4//4 - 1)*4
        answer += 1
        
        print (primes[answer])
        