#!/usr/bin/env python3
import math

primes = [1]*62001
primer = []
for i in range(2,int(math.sqrt(62000))):
    for j in range(i*i,62000,i):
        primes[j] = 0
for i in range(2,62000):
    if primes[i]:
        primer.append(i)
del primes

#print (primer)
test = int(input())
for i in range(test):
    n = int(input())
    count = 0
    array = []
    z = 1
    for x in primer:
        if x > n:
            break
        while n%x == 0:
            count += 1
            array.append(x)
            #z *= x
            n = n//x
    #y = n//z
    if n > 1:
        array.append(n)
        count += 1
    if(count == 0):
        print(1)
        print(n)
    else:
        print(count)
        for x in array:
            print(x)
    
