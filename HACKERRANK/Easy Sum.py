#!/usr/bin/env python3
#https://www.hackerrank.com/contests/infinitum-jun14/challenges/easy-sum
test = int(input())
for _ in range(test):
    stri = input().split()
    n , m = int(stri[0]), int(stri[1])
    numbers = 0
    numbers = ((m-1)*m)//2
    multi = n//m
    answer = numbers*multi
    multi = n%m
    answer += (multi*(multi+1))//2
    print(answer)