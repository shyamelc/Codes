#!/usr/bin/env python3
#https://www.hackerrank.com/contests/project-euler/challenges/euler001

test = int(input())
for i in range(test):
    n = int(input())
    summ = 0
    for i in range(3,n,3):
        summ += i
    for i in range(5,n,5):
        summ += i
    for i in range(15,n,15):
        summ -= i
    print(summ)
